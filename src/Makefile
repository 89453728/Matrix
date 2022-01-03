## Makefile
##
## Copyright (C) 2020-2021 Yassin Achengli <0619883460@uma.es>
## 
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program; see the file COPYING.  If not, see
## <https://www.gnu.org/licenses/>.
##
## ======================================================================
##

G = g++ -g -Wall 
OFILES = cmplx.o main.o
EXEC = main
TEST = ../test/

all: move compile

compile: 
	$(G) -o $(TEST)$(EXEC) $(TEST)$(OFILES)	
	
move: $(OFILES)
	@echo "moving all to test"
	cp *.o $(TEST)
%.o: %.cc %.h
	@echo "Compiling $? file"
	$(G) -c $?  
clean:
	rm -rf *.o 
	rm *.gch
cleantest: 
	tm -rf $(TEST)*.o $(TEST)*.oct 
