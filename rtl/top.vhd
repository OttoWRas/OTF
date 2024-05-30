-- -----------------------------------------------------------------------------
--
--  Title      :  Top level for accelerator flow OTF.
--             :
--  Developers :  Luca Pezzarossa - lpez@dtu.dk
--             :  Otto Rasmussen  - otto.westy.rasmussen@gmail.com  
--             :
--  Purpose    :  A top-level entity connecting all the components.
--             :
--             :
--  Revision   :  1.2    22-05-24    Initial version
--
-- -----------------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use work.types.all;

entity top is
    port(
        clk_100mhz : in  std_logic;
        rst        : in  std_logic;
        led        : out std_logic;
        start      : in  std_logic;
        -- Serial interface for PC communication
        serial_tx  : in  STD_LOGIC;     -- from the PC
        serial_rx  : out STD_LOGIC      -- to the PC
    );
end top;

architecture structure of top is

    component tvmgen_default_run is
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
    end component;

    -- The accelerator clock frequency will be (100MHz/CLK_DIVISION_FACTOR)
    constant CLK_DIVISION_FACTOR : integer := 2; --(1 to 7)

    signal clk   : bit_t;
    signal rst_s : std_logic;

    signal addr     : halfword_t;
    signal dataR    : word_t;
    signal dataW    : word_t;
    signal en       : bit_t;
    signal we       : bit_t;
    
    signal done_acc     : std_logic;
    signal ready_acc    : std_logic;
    signal start_acc    : std_logic;
    signal idle_acc     : std_logic;
    
    attribute mark_debug :  string;
    attribute mark_debug of done_acc: signal is "true";
    attribute mark_debug of ready_acc: signal is "true";
    attribute mark_debug of start_acc: signal is "true";
    attribute mark_debug of idle_acc: signal is "true";
    attribute mark_debug of dataW: signal is "true";
    attribute mark_debug of we: signal is "true";

    signal a_mem_enb   : std_logic;
    signal a_mem_web   : std_logic;
    signal a_mem_addr : std_logic_vector(11 downto 0);
    signal a_mem_dib   : std_logic_vector(31 downto 0);
    signal a_mem_dob   : std_logic_vector(31 downto 0);
    
    signal b_mem_enb   : std_logic;
    signal b_mem_web   : std_logic;
    signal b_mem_addr : std_logic_vector(11 downto 0);
    signal b_mem_dib   : std_logic_vector(31 downto 0);
    signal b_mem_dob   : std_logic_vector(31 downto 0);
    
    attribute mark_debug of b_mem_addr: signal is "true";

    signal data_stream_in      : std_logic_vector(7 downto 0);
    signal data_stream_in_stb  : std_logic;
    signal data_stream_in_ack  : std_logic;
    signal data_stream_out     : std_logic_vector(7 downto 0);
    signal data_stream_out_stb : std_logic;

    signal in_addr : std_logic_vector(11 downto 0);
    signal in_enable : std_logic;
    signal out_addr : std_logic_vector(11 downto 0);
    signal out_enable : std_logic;

begin
    led <= done_acc;

    clock_divider_inst_0 : entity work.clock_divider
        generic map(
            DIVIDE => CLK_DIVISION_FACTOR
        )
        port map(
            clk_in  => clk_100mhz,
            clk_out => clk
        );

    accelerator_inst_0 : tvmgen_default_run
        port map(
            ap_clk    => clk,
            ap_rst    => rst_s,
            ap_start  => start_acc,
            ap_done   => done_acc,
            ap_ready  => ready_acc,
            ap_idle   => idle_acc,
            input_r_address0  => in_addr,
            input_r_q0  => dataR,
            input_r_ce0 => in_enable,
            output_r_address0 => out_addr,
            output_r_d0  => dataW,
            output_r_we0 => we,
            output_r_ce0 => out_enable
        );

    controller_inst_0 : entity work.controller
        generic map(
            MEMORY_ADDR_SIZE => 12
        )
        port map(
            clk                => clk,
            reset              => rst_s,
            data_stream_tx     => data_stream_in,
            data_stream_tx_stb => data_stream_in_stb,
            data_stream_tx_ack => data_stream_in_ack,
            data_stream_rx     => data_stream_out,
            data_stream_rx_stb => data_stream_out_stb,
            
            o_acc_start => start_acc,
            i_acc_idle => idle_acc,
            i_acc_done  => done_acc,
            
            in_mem_en             => a_mem_enb,
            in_mem_we             => a_mem_web,
            in_mem_addr           => a_mem_addr,
            in_mem_dw             => a_mem_dib,
            in_mem_dr             => a_mem_dob,
            
            out_mem_en             => b_mem_enb,
            out_mem_we             => b_mem_web,
            out_mem_addr           => b_mem_addr,
            out_mem_dw             => b_mem_dib,
            out_mem_dr             => b_mem_dob
        );

    uart_inst_0 : entity work.uart
        generic map(
            baud            => 115200,
            clock_frequency => positive(100_000_000 / CLK_DIVISION_FACTOR)
        )
        port map(
            clock               => clk,
            reset               => rst_s,
            data_stream_in      => data_stream_in,
            data_stream_in_stb  => data_stream_in_stb,
            data_stream_in_ack  => data_stream_in_ack,
            data_stream_out     => data_stream_out,
            data_stream_out_stb => data_stream_out_stb,
            tx                  => serial_rx,
            rx                  => serial_tx
        );

    memory3_inst_0 : entity work.memory3
        generic map(
            ADDR_SIZE => 12
        )
        port map(
            clk   => clk,
            -- Port a (for the accelerator)
            ena   => in_enable,
            wea   => we,
            addra => in_addr,
            dia   => a_mem_dib,
            doa   => dataR,
            -- Port b (for the uart/controller)
            enb   => a_mem_enb,
            web   => a_mem_web,
            addrb => a_mem_addr,
            dib   => a_mem_dib,
            dob   => a_mem_dob
        );
        
    memory3_inst_1 : entity work.memory3
        generic map(
            ADDR_SIZE => 12
        )
        port map(
            clk   => clk,
            -- Port a (for the accelerator)
            ena   => out_enable,
            wea   => we,
            addra => out_addr,
            dia   => dataW,
            -- Port b (for the uart/controller)
            enb   => b_mem_enb,
            web   => b_mem_web,
            addrb => b_mem_addr,
            dib   => b_mem_dib,
            dob   => b_mem_dob
        );

end structure;
