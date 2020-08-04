#include "NodeAP.h"

extern WiFiUDP Udp; //from Node_NTP
int status = WL_IDLE_STATUS;
extern int keyIndex;            // your network key Index number (needed only for WEP)
int PacketSize = 0;
int len;

//unsigned int localPort = 2390;  // local port to listen on
extern unsigned int localPort;    // local port to listen on
extern char packetBuffer[255];    // buffer to hold incoming packet
char  ReplyBuffer[255];       // a string to send back

void LocalUdpLoop(void)
{
  PacketSize = Udp.parsePacket();

  if (PacketSize)
  {
    IPAddress remoteIp = Udp.remoteIP();

    Serial.print("Receive UDP size "); Serial.print(PacketSize);
    Serial.print("|");                 Serial.print(remoteIp);
    Serial.print("|");                 Serial.print(Udp.remotePort());

    // read the packet into packetBufffer
    len = Udp.read(packetBuffer, 255);

    if (len > 0)
    {
      packetBuffer[len] = 0;
    }

    Serial.print("|");   Serial.println(packetBuffer);
    Serial.println();

    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
}
