//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package tictoc.simulations;

import tictoc.Txc;

import wampinterfaceforomnetpp.SimulationCallee;
//
// Two instances (tic and toc) of Txc connected.
//
network Tictoc
{
    submodules:
        callee: SimulationCallee {
            @display("p=78,95");
        }
        tic: Txc {
            @display("p=29,27;i=device/accesspoint");
        }
        toc: Txc {
            @display("p=133,27;i=device/accesspoint");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
