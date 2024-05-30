-- ==============================================================
-- Generated by Vitis HLS v2023.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity tvmgen_default_run_tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu_1_Pipeline_VITIS_LOObkb is 
    generic(
             DataWidth     : integer := 32; 
             AddressWidth     : integer := 8; 
             AddressRange    : integer := 200
    ); 
    port (
 
          address0        : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0             : in std_logic; 
          q0              : out std_logic_vector(DataWidth-1 downto 0);

          reset               : in std_logic;
          clk                 : in std_logic
    ); 
end entity; 


architecture rtl of tvmgen_default_run_tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu_1_Pipeline_VITIS_LOObkb is 
 
signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 

type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 

signal mem0 : mem_array := (
    0 => "10111100000100011110100100010110", 1 => "10111101001000110101101110101100", 2 => "10111100110000100000011110001100", 3 => "10111110100101110011100000100101", 
    4 => "10111110011100101001011111011101", 5 => "00111110010111111101100010100001", 6 => "00111101110101100000011011100110", 7 => "10111110101010100011001001100100", 
    8 => "10111111000000100100001000100011", 9 => "00111110111111110101100100100111", 10 => "00111110100000011101101101101101", 11 => "10111110101001111110111011101000", 
    12 => "10111101100001000011100011110111", 13 => "00111110110110001110101110000010", 14 => "00111110101110010011101000011111", 15 => "10111101101000100011011110111101", 
    16 => "00111110000100010011011100100000", 17 => "00111101010001101101101000001100", 18 => "00111111001100001110001011101011", 19 => "10111110011000111100010011111001", 
    20 => "10111111000101111000101111000000", 21 => "10111101110011110011100001011110", 22 => "00111110101010110111101000101110", 23 => "10111110111101000001101001000011", 
    24 => "10111110111100110101100010011011", 25 => "10111110100011011100011100010100", 26 => "00111110110101011000000011111100", 27 => "10111110010101111100010111111101", 
    28 => "10111101010010100010000101001000", 29 => "10111011100100000010010110110101", 30 => "00111110110001010000100000111100", 31 => "10111101011010111010001110010100", 
    32 => "00111111010001001010100111000111", 33 => "00111111000001101111010011000010", 34 => "00111110101010001010100001110000", 35 => "00111110001001111010101100101010", 
    36 => "00111110100001101110010011101001", 37 => "00111110110011101000101110110011", 38 => "00111110011110001101100011101001", 39 => "00111110001001011101110010011011", 
    40 => "10111110111110111100100001101011", 41 => "10111110000110100111010101000000", 42 => "10111110111100000010101000001001", 43 => "10111110110010001001000001001100", 
    44 => "00111101011000111100111101010110", 45 => "10111110101001110100010011100111", 46 => "10111101100110111001000001010101", 47 => "10111100110000001010000001011101", 
    48 => "00111111100000100110110101101110", 49 => "10111110001000101100110100101000", 50 => "10111110000100111111111001011011", 51 => "00111101111111000111001100000111", 
    52 => "00111111000011100000000100011000", 53 => "00111110101101111100111001001110", 54 => "10111110001100011011101001100101", 55 => "00111101001011011010101110100100", 
    56 => "10111110111000100010000111010110", 57 => "00111110101111101100101000010111", 58 => "10111110011111001011000101110000", 59 => "00111110011010011000010110110010", 
    60 => "10111110001000110101110110101010", 61 => "10111111000100010101001101000010", 62 => "10111111011110010000000110100011", 63 => "00111101110000011001111001110010", 
    64 => "00111111000011101011101100001010", 65 => "10111110110001010111110010100000", 66 => "10111111001101110011001010110011", 67 => "00111110101111100111101110100110", 
    68 => "00111111000101111001001101001011", 69 => "10111110001100011101110101000100", 70 => "10111111000010011100100001001111", 71 => "00111110011000001010011100001110", 
    72 => "10111110100101101110100001011000", 73 => "00111110011010011000001010011111", 74 => "10111111000111011110010101001001", 75 => "10111100001101111000000101101101", 
    76 => "10111111000111001111100101011010", 77 => "00111110101010100101111000010100", 78 => "10111110111001011001101101110000", 79 => "00111110001110011000011000111101", 
    80 => "00111101000111011011000011111000", 81 => "10111110110000101111010111010101", 82 => "10111110010010111100001000100110", 83 => "00111110101001111011000010100010", 
    84 => "00111110011001110111000110011011", 85 => "10111110011010101111110010110011", 86 => "10111110101010101010110110011111", 87 => "00111110101100111100010110000110", 
    88 => "10111110010111111100110100111001", 89 => "10111101100001111010100010101111", 90 => "10111110101100101011101000101001", 91 => "00111100111011100001101000110001", 
    92 => "10111110111101000101001011010000", 93 => "10111100011011101001000001000010", 94 => "10111110000101011000101001100111", 95 => "00111110010101100011111001011111", 
    96 => "10111110100101010101101001011010", 97 => "00111110100100011101111111111111", 98 => "10111101100000100011111110001010", 99 => "00111110101011100111001001110010", 
    100 => "10111110010110111011000000001100", 101 => "10111110001010100000011111101011", 102 => "00111101110010001010010101000111", 103 => "10111100101101001110110100100110", 
    104 => "10111101111110011111010000111110", 105 => "10111110101010101110100110111101", 106 => "00111111000011110011101001100100", 107 => "10111110000001110010110001001000", 
    108 => "10111011000111000000001001010000", 109 => "10111110010000111100100001111000", 110 => "10111110010110111001010000010110", 111 => "00111101101110111100010111111000", 
    112 => "10111110011001110010100000101011", 113 => "00111101010110110010000011011101", 114 => "10111110111010100101010010101001", 115 => "00111110011011010010101001010110", 
    116 => "10111110001001010000100001000111", 117 => "00111110000100001111100011111100", 118 => "10111110010110001110100011100100", 119 => "00111110101011011111001010110000", 
    120 => "00111101101101100101111011001100", 121 => "00111110001110110100001010010000", 122 => "00111110101110101001001111101100", 123 => "00111110001010010000001011000001", 
    124 => "00111110010100011110010100110101", 125 => "10111111000011000100111100010000", 126 => "00111110111110010110000001000101", 127 => "00111110110000001100001001110001", 
    128 => "10111110001000000001100110111100", 129 => "10111111001110111011100001001101", 130 => "10111110110100001011101101010110", 131 => "00111110010001111011010111101110", 
    132 => "10111110011001110001000111010010", 133 => "10111111000101101001100010110010", 134 => "10111110110110111100000001101001", 135 => "00111110101000010101110111111010", 
    136 => "10111111000011111110010110101101", 137 => "10111110110001001011100100000011", 138 => "10111110011111010111110000000001", 139 => "00111111000100010011000000100010", 
    140 => "10111101011101101011100010001000", 141 => "00111111000010100101000000001001", 142 => "00111110110101000111000110001100", 143 => "10111101111100011010110001010111", 
    144 => "00111110110100100010010000011010", 145 => "00111110101100010011011110001110", 146 => "00111110100110011001101101011000", 147 => "00111110010010001010111101111010", 
    148 => "10111100011011010101110011111000", 149 => "10111110100000010010110010011101", 150 => "10111110111010100111000100000001", 151 => "00111110000001111011110010010001", 
    152 => "10111110111100110010100101011000", 153 => "10111110101100010110110100000110", 154 => "10111110100110111001101011010000", 155 => "00111101010000111011111111111101", 
    156 => "10111111000100000110010111110000", 157 => "10111110010101111111101000100110", 158 => "10111101101101110110000001011001", 159 => "00111110000010001101100111010001", 
    160 => "10111101111011001010101111101010", 161 => "00111110011000010110111100101001", 162 => "00111110100011100101110100110100", 163 => "00111100111010000111010111111001", 
    164 => "00111110000100011000000111010111", 165 => "00111111001010001010111010101111", 166 => "00111101111010100101101011011101", 167 => "10111110000011100111110110001110", 
    168 => "00111110100011011011000010110110", 169 => "00111110101110101100010011111110", 170 => "10111110001100000111001100010111", 171 => "10111101111101110101100111111100", 
    172 => "00111101001011100111110000111111", 173 => "00111110000001000111101010001110", 174 => "10111110101101000000111100100101", 175 => "10111110010010100100010111100100", 
    176 => "10111100001111010011100110110010", 177 => "10111101111000000110000010111110", 178 => "10111110000110111010110101110001", 179 => "10111111000000001001010111011110", 
    180 => "00111100000111101101110100001101", 181 => "00111101011101101011000010000101", 182 => "00111110101100101000010011111000", 183 => "10111101000100101011101101110001", 
    184 => "00111110011111000000010101010010", 185 => "00111110100110110000111110001111", 186 => "00111110001111100100000110001000", 187 => "10111110010000100110001001001011", 
    188 => "00111111001000000010100000110001", 189 => "00111110011100101010110001111000", 190 => "00111101100100010010110100010100", 191 => "10111110110110101110011000011010", 
    192 => "00111111001011101110101001100010", 193 => "00111110111100000011010010110000", 194 => "00111110000010010110010110010011", 195 => "10111110100100011100101010001000", 
    196 => "00111110011100011011110001111001", 197 => "00111110011001001010011011101111", 198 => "10111101001111010010101000111100", 199 => "10111110010000101110101100011001");



begin 

 
memory_access_guard_0: process (address0) 
begin
      address0_tmp <= address0;
--synthesis translate_off
      if (CONV_INTEGER(address0) > AddressRange-1) then
           address0_tmp <= (others => '0');
      else 
           address0_tmp <= address0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
 
        if (ce0 = '1') then  
            q0 <= mem0(CONV_INTEGER(address0_tmp)); 
        end if;

end if;
end process;

end rtl;
