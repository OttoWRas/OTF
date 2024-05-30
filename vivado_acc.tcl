file mkdir /rtl/tmp
create_project project_acc_project ./rtl/tmp/acc_project
-part xc7a100tcsg324-1

add_files ./rtl/*.vhd
source /rtl/acc/*.tcl
add_files ./rtl/acc/*.vhd