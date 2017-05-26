----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:00:40 04/18/2017 
-- Design Name: 
-- Module Name:    decode - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity decode is
    Port ( DataIN : in  STD_LOGIC_VECTOR (31 downto 0);
           OP : out  STD_LOGIC_VECTOR (7 downto 0);
           A : out  STD_LOGIC_VECTOR (15 downto 0);
           B : out  STD_LOGIC_VECTOR (15 downto 0);
           C : out  STD_LOGIC_VECTOR (15 downto 0));
end decode;

architecture Behavioral of decode is
	signal optmp : STD_LOGIC_VECTOR (7 downto 0);
	signal abctmp : STD_LOGIC_VECTOR (23 downto 0);

begin

optmp <= DataIN(31 downto 24);
abctmp <= DataIN(23 downto 0);
OP <= optmp;

abc : process (optmp,abctmp) is
begin
	case optmp is
	when x"05" => --COP, OP, A, B
		A <= x"00"&abctmp(23 downto 16);
		B <= x"00"&abctmp(15 downto 8);
		C <= x"0000";
	when x"06" => --AFC, OP, A, B/16
		A <= x"00"&abctmp(23 downto 16);
		B <= abctmp(15 downto 0);
		C <= x"0000";
	when x"07" => --LOAD, OP, R31/C, offset/B, Ri/A
		A <= x"00"&abctmp(7 downto 0);
		B <= x"00"&abctmp(15 downto 8);
		C <= x"00"&abctmp(23 downto 16);
	when x"08" => --STORE, OP, Ri/B, R31/C, offset/A
		A <= x"00"&abctmp(7 downto 0);
		B <= x"00"&abctmp(23 downto 16);
		C <= x"00"&abctmp(15 downto 8);
	when x"0E" => --JMP, OP, A/16
		A <= abctmp(23 downto 8);
		B <= x"0000";
		C <= x"0000";
	when x"0F" => --JMPC, A/16, B
		A <= abctmp(23 downto 8);
		B <= x"00"&abctmp(7 downto 0);
		C <= x"0000";
	when x"10" => --JMPR, Ri/B
		A <= x"0000";
		B <= x"00"&abctmp(23 downto 16);
		C <= x"0000";
	when others => --OP, A, B, C
		A <= x"00"&abctmp(23 downto 16);
		B <= x"00"&abctmp(15 downto 8);
		C <= x"00"&abctmp(7 downto 0);
	end case;
end process;


end Behavioral;

