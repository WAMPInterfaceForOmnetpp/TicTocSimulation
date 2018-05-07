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

#ifndef __TICTOC_TCX_H
#define __TICTOC_TCX_H

#include <omnetpp.h>

namespace tictoc {
/**
 * Implements the Txc simple module. See the NED file for more information.
 */
class Txc : public omnetpp::cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(omnetpp::cMessage *msg);
    static omnetpp::simsignal_t arrivalSignal;
    omnetpp::simtime_t sleepTime;

  public:
    void handleParameterChange(const char *parname);
};}
#endif
