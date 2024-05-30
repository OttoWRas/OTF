# STEP#1: define the output directory area.
#
set outputDir ./synth/
file mkdir $outputDir
create_project project_acc ./tmp/acc_project \
 -part xc7a100tcsg324-1 -force
#
# STEP#2: setup design sources and constraints
#
add_files [ glob ./rtl/*.vhd]
foreach f [ glob ./rtl/acc/*.tcl ] {
   source $f 
}
add_files [ glob ./rtl/acc/*.vhd]
#
# Physically import the files under project_cpu.srcs/sources_1/imports directory
import_files -force -norecurse
#
# Physically import bft_full.xdc under project_cpu.srcs/constrs_1/imports directory
import_files -fileset constrs_1 -force -norecurse ./rtl/Nexys4DDR_edge.xdc
# Update compile order for the fileset 'sources_1'
set_property top top [current_fileset]
update_compile_order -fileset sources_1