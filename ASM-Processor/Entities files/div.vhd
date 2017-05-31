
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity div is
    Port ( CLK : in  STD_LOGIC;
			  RST : in  STD_LOGIC;
           CLK_2 : out  STD_LOGIC;
           CLK_4 : out  STD_LOGIC);
end div;

architecture Behavioral of div is
	signal clk2 : STD_LOGIC :='0';
	signal clk4 : STD_LOGIC :='0';
begin

div0 : process (CLK) begin
 if rising_edge(CLK) then
	if (RST = '0') then
	  clk2 <= '0';
	else
	  clk2 <= clk2 xor '1';
	end if;
 end if;
end process;

div1 : process (clk2)
begin
 if rising_edge(clk2) then
	if (RST = '0') then
	  clk4 <= '0';
	else
	  clk4 <= clk4 xor '1';
	end if;
 end if;
end process;

CLK_2 <= clk2;
CLK_4 <= clk4;


end Behavioral;

