----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:01:57 04/18/2017 
-- Design Name: 
-- Module Name:    regs - Behavioral 
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
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
				
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity regs is
    Port ( adrA : in  STD_LOGIC_VECTOR (4 downto 0);
           adrB : in  STD_LOGIC_VECTOR (4 downto 0);
           adrW : in  STD_LOGIC_VECTOR (4 downto 0);
           W : in  STD_LOGIC;
           Data : in  STD_LOGIC_VECTOR (15 downto 0);
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           QA : out  STD_LOGIC_VECTOR (15 downto 0);
           QB : out  STD_LOGIC_VECTOR (15 downto 0));
end regs;

architecture Behavioral of regs is
	type registres is array (integer range 31 downto 0) of STD_LOGIC_VECTOR(15 downto 0);
	signal reg : registres;
begin

rw : process (CLK) is
begin
	if falling_edge(CLK) then
		if(RST = '0') then
		-- registres = 0x00
		reg <= (others =>(others => '0' ));
		else
		-- traiter read et flag write
			if W = '1' then
				-- avec W, ecrire et puis lire
				reg(conv_integer(adrW)) <= Data;
				-- si un read a le meme adresse que adrW et W = '1' alors read Data
				if (adrA = adrW) then
					QA <= Data;
				else
					QA <= reg(conv_integer(adrA));
				end if;
				if (adrB = adrW) then
					QB <= Data;
				else
					QB <= reg(conv_integer(adrB));
				end if;
			else
			   -- read
				QA <= reg(conv_integer(adrA));
				QB <= reg(conv_integer(adrB));
			end if;
			
		end if;
	end if;
end process;


end Behavioral;

