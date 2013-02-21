/****************************************************************************************************

RepRapFirmware - Webserver

This class serves web pages to the attached network.  These pages form the user's interface with the
RepRap machine.  It interprests returned values from those pages and uses them to Generate G Codes,
which it sends to the RepRap.  It also collects values from the RepRap like temperature and uses
those to construct the web pages.

-----------------------------------------------------------------------------------------------------

Version 0.1

13 February 2013

Adrian Bowyer
RepRap Professional Ltd
http://reprappro.com

Licence: GPL

****************************************************************************************************/

#ifndef WEBSERVER_H
#define WEBSERVER_H

#define CLIENT_CLOSE_DELAY 1000 // Microseconds to wait after serving a page

#define PASSWORD_PAGE "passwd.htm"
#define STRING_LENGTH 1000

class Webserver
{   
  public:
  
    Webserver(Platform* p);
    boolean Available();
    byte Read();
    void spin();
    
  private:
  
    void ParseClientLine();
    void IncomingByte(unsigned char b);
    void SendFile(char* nameOfFileToSend);
    void WriteByte();
    boolean StringEndsWith(char* string, char* ending);
    boolean StringStartsWith(char* string, char* starting);
    void ParseQualifier();
    void CheckPassword();
    boolean LoadGcodeBuffer(char* gc, boolean convertWeb);
    boolean InternalFile(char* nameOfFileToSend);
    void InternalHead(boolean sendTab, int noLink, char* headString);
    void InternalTail();
    void CloseClient();
    void SendControlPage();
    void SendPrintPage();
    void SendHelpPage();
    void SendSettingsPage();
    void SendLogoutPage();
    void SendPasswordPage();
    void Send404Page();
    
    Platform* platform;
    unsigned long lastTime;
    int fileBeingSent;
    boolean writing;
    boolean clientLineIsBlank;
    unsigned long clientCloseTime;
    boolean needToCloseClient;
    char clientLine[STRING_LENGTH];
    char clientRequest[STRING_LENGTH];
    char clientQualifier[STRING_LENGTH];
    char gcodeBuffer[GCODE_LENGTH];
    boolean gcodeAvailable;
    int gcodePointer;
    int clientLinePointer;
    boolean gotPassword;
    char* password;
    char* myName;
};


#endif
