----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:58:47 05/02/2017 
-- Design Name: 
-- Module Name:    muxual - Behavioral 
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

entity muxual is
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           S : in  STD_LOGIC_VECTOR (15 downto 0);
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0));
end muxual;

architecture Behavioral of muxual is

begin

multiplexeur : process (OP, B, S) is
begin
	case OP is -- out<=S if calcul
	when x"01" => --ADD
		DataOUT <= S;
	when x"02" => --MUL
		DataOUT <= S;
	when x"03" => --SUB
		DataOUT <= S;
	when x"04" => --DIV
		DataOUT <= S;
	when x"07" => --LOAD R31+offset
		DataOUT <= S;
	when x"08" => --store R31+offset
		DataOUT <= S;
	when others => 
		DataOUT <= B;
	end case;
end process;

end Behavioral;

