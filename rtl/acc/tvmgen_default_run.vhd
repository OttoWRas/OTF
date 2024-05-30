-- ==============================================================
-- Generated by Vitis HLS v2023.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- ==============================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tvmgen_default_run is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    input_r_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
    input_r_ce0 : OUT STD_LOGIC;
    input_r_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    output_r_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
    output_r_ce0 : OUT STD_LOGIC;
    output_r_we0 : OUT STD_LOGIC;
    output_r_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    ap_return : OUT STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of tvmgen_default_run is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "tvmgen_default_run_tvmgen_default_run,hls_ip_2023_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7a35t-cpg236-1,HLS_INPUT_CLOCK=8.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.259000,HLS_SYN_LAT=11229998,HLS_SYN_TPT=none,HLS_SYN_MEM=33,HLS_SYN_DSP=0,HLS_SYN_FF=15537,HLS_SYN_LUT=28050,HLS_VERSION=2023_2}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (1 downto 0) := "01";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal grp_tvmgen_default_tvm_main_1_fu_38_ap_start : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_ap_done : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_ap_idle : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_ap_ready : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_input_r_address0 : STD_LOGIC_VECTOR (11 downto 0);
    signal grp_tvmgen_default_tvm_main_1_fu_38_input_r_ce0 : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_output_r_address0 : STD_LOGIC_VECTOR (11 downto 0);
    signal grp_tvmgen_default_tvm_main_1_fu_38_output_r_ce0 : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_output_r_we0 : STD_LOGIC;
    signal grp_tvmgen_default_tvm_main_1_fu_38_output_r_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_tvmgen_default_tvm_main_1_fu_38_ap_start_reg : STD_LOGIC := '0';
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal ap_NS_fsm : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_ST_fsm_state2_blk : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component tvmgen_default_run_tvmgen_default_tvm_main_1 IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        input_r_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
        input_r_ce0 : OUT STD_LOGIC;
        input_r_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        output_r_address0 : OUT STD_LOGIC_VECTOR (11 downto 0);
        output_r_ce0 : OUT STD_LOGIC;
        output_r_we0 : OUT STD_LOGIC;
        output_r_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    grp_tvmgen_default_tvm_main_1_fu_38 : component tvmgen_default_run_tvmgen_default_tvm_main_1
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_tvmgen_default_tvm_main_1_fu_38_ap_start,
        ap_done => grp_tvmgen_default_tvm_main_1_fu_38_ap_done,
        ap_idle => grp_tvmgen_default_tvm_main_1_fu_38_ap_idle,
        ap_ready => grp_tvmgen_default_tvm_main_1_fu_38_ap_ready,
        input_r_address0 => grp_tvmgen_default_tvm_main_1_fu_38_input_r_address0,
        input_r_ce0 => grp_tvmgen_default_tvm_main_1_fu_38_input_r_ce0,
        input_r_q0 => input_r_q0,
        output_r_address0 => grp_tvmgen_default_tvm_main_1_fu_38_output_r_address0,
        output_r_ce0 => grp_tvmgen_default_tvm_main_1_fu_38_output_r_ce0,
        output_r_we0 => grp_tvmgen_default_tvm_main_1_fu_38_output_r_we0,
        output_r_d0 => grp_tvmgen_default_tvm_main_1_fu_38_output_r_d0);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    grp_tvmgen_default_tvm_main_1_fu_38_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_tvmgen_default_tvm_main_1_fu_38_ap_start_reg <= ap_const_logic_0;
            else
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                    grp_tvmgen_default_tvm_main_1_fu_38_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_tvmgen_default_tvm_main_1_fu_38_ap_ready = ap_const_logic_1)) then 
                    grp_tvmgen_default_tvm_main_1_fu_38_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, grp_tvmgen_default_tvm_main_1_fu_38_ap_done, ap_CS_fsm_state2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((grp_tvmgen_default_tvm_main_1_fu_38_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when others =>  
                ap_NS_fsm <= "XX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);

    ap_ST_fsm_state1_blk_assign_proc : process(ap_start)
    begin
        if ((ap_start = ap_const_logic_0)) then 
            ap_ST_fsm_state1_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state1_blk <= ap_const_logic_0;
        end if; 
    end process;


    ap_ST_fsm_state2_blk_assign_proc : process(grp_tvmgen_default_tvm_main_1_fu_38_ap_done)
    begin
        if ((grp_tvmgen_default_tvm_main_1_fu_38_ap_done = ap_const_logic_0)) then 
            ap_ST_fsm_state2_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state2_blk <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_assign_proc : process(grp_tvmgen_default_tvm_main_1_fu_38_ap_done, ap_CS_fsm_state2)
    begin
        if (((grp_tvmgen_default_tvm_main_1_fu_38_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(grp_tvmgen_default_tvm_main_1_fu_38_ap_done, ap_CS_fsm_state2)
    begin
        if (((grp_tvmgen_default_tvm_main_1_fu_38_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    ap_return <= ap_const_lv32_0;
    grp_tvmgen_default_tvm_main_1_fu_38_ap_start <= grp_tvmgen_default_tvm_main_1_fu_38_ap_start_reg;
    input_r_address0 <= grp_tvmgen_default_tvm_main_1_fu_38_input_r_address0;
    input_r_ce0 <= grp_tvmgen_default_tvm_main_1_fu_38_input_r_ce0;
    output_r_address0 <= grp_tvmgen_default_tvm_main_1_fu_38_output_r_address0;
    output_r_ce0 <= grp_tvmgen_default_tvm_main_1_fu_38_output_r_ce0;
    output_r_d0 <= grp_tvmgen_default_tvm_main_1_fu_38_output_r_d0;
    output_r_we0 <= grp_tvmgen_default_tvm_main_1_fu_38_output_r_we0;
end behav;
