----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:43:10 04/27/2017 
-- Design Name: 
-- Module Name:    ip - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ip is
    Port ( DIN : in  STD_LOGIC_VECTOR (15 downto 0);
           DOUT : out  STD_LOGIC_VECTOR (15 downto 0);
           CLK : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           LOAD : in  STD_LOGIC;
           EN : in  STD_LOGIC);
end ip;

architecture Behavioral of ip is
	--Declaration
	--Signal de la mémoire interne qu'on va incrémenter de 1 à chaque itération
	signal memory : STD_LOGIC_VECTOR (15 downto 0);
	signal change : STD_LOGIC :='0';

begin
--Corps

DOUT <= memory;

--  le compter on fait un process sur la CLK
compter : process (CLK,EN) is
begin
    --Si on est sur un front montant de la clock + ' 1' "00000001"
    if rising_edge(CLK) then
        if(RST = '0') then
            memory <= x"0000";
				change <= '0';
        else
            if(LOAD='1') then
                memory <= DIN;
					 change <= '0';
            else
                if(EN='0') then
                    memory <= memory+x"0001";
						  change <= '1';
					 else
						  if(change ='1') then 
								memory <= memory-x"0002";
								change <= '0';
						  end if;
                end if;
            end if;
        end if;
    end if;
end process;


end Behavioral;

