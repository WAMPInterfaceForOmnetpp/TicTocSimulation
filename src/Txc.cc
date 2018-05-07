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

#include "Txc.h"
#include "LiveRecorder.h"

namespace tictoc {

simsignal_t Txc::arrivalSignal = registerSignal("arrival");
Define_Module(Txc);

char topic[] = "com.examples.subscriptions.topic1";
Register_ResultRecorder("tictoc_live", wampinterfaceforomnetpp::LiveRecorder<topic>());

void Txc::initialize()
{
    if (par("sendInitialMessage").boolValue())
    {
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc::handleMessage(cMessage *msg)
{
    // just send back the message we received
    send(msg, "out");
    emit(arrivalSignal, 1);
}

}; // namespace
