----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:11:12 05/13/2017 
-- Design Name: 
-- Module Name:    ctljump - Behavioral 
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

entity ctljump is
    Port ( decOPin : in  STD_LOGIC_VECTOR (7 downto 0);
           decAin : in  STD_LOGIC_VECTOR (15 downto 0);
			  lidiNOPout : out STD_LOGIC;
           ipLOADout : out  STD_LOGIC;
           ipDINout : out  STD_LOGIC_VECTOR (15 downto 0));
end ctljump;

architecture Behavioral of ctljump is
	 signal NOPcounter: STD_LOGIC := '0';

begin
	
jump : process (decOPin, decAin) is
begin
	case decOPin is
	when x"0E" => -- JMP, @i
		 lidiNOPout <= '0';
		 ipLOADout <= '1';
		 ipDINout <= decAin;
		 NOPcounter <= '1';
	when others => -- do nothing
		if (NOPcounter = '1') then
			lidiNOPout <= '1';
		else
			lidiNOPout <= '0';
		end if;
		ipLOADout <= '0';
		ipDINout <= decAin;
		NOPcounter <= '0';
	end case;
end process;


end Behavioral;

