--------------------------------------------------------------------------------
-- Dual-Port Block ram with Two Write Ports Modelized with a Shared Variable
-- --LITTLE ENDIAN--
--
-- Data size is 32 bits, memory size is 2^ADDR_SIZE
--
-- File: HDL_Coding_Techniques/rams/rams_8b.vhd
--------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity memory3 is
    generic(
        ADDR_SIZE : integer := 16
    );
    port(
        clk   : in  std_logic;
        --port a
        ena   : in  std_logic;
        wea   : in  std_logic;
        addra : in  std_logic_vector(ADDR_SIZE - 1 downto 0);
        dia   : in  std_logic_vector(31 downto 0);
        doa   : out std_logic_vector(31 downto 0);
        --port b
        enb   : in  std_logic;
        web   : in  std_logic;
        addrb : in  std_logic_vector(ADDR_SIZE - 1 downto 0);
        dib   : in  std_logic_vector(31 downto 0);
        dob   : out std_logic_vector(31 downto 0)
    );
end memory3;

architecture rtl of memory3 is
    type ram_type is array (2 ** ADDR_SIZE downto 0) of std_logic_vector(31 downto 0);
    shared variable ram : ram_type;
begin
    process(clk)
    begin
        if clk'event and clk = '1' then
            if ena = '1' then
                doa <= ram(conv_integer(ADDRA));
                if wea = '1' then
                    ram(conv_integer(ADDRA)) := DIA;
                end if;
            end if;
        end if;
    end process;

    process(clk)
    begin
        if clk'event and clk = '1' then
            if enb = '1' then
                dob <= ram(conv_integer(ADDRB));
                if web = '1' then
                    ram(conv_integer(ADDRB)) := DIB;
                end if;
            end if;
        end if;
    end process;
end rtl;
