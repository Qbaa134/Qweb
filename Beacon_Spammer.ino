const uint8_t channels[] = {1, 6, 11}; 
const bool wpa2 = false; 
const bool appendSpaces = true;

const char ssids[] PROGMEM = {
  "Kabel mi urwiesz\n"
  "Miejskie\n"
  "WiFiZSamsung\n"
  "SuperInternet\n"
  "Kanalizacja\n"
  "SkrzynkaToshiba\n"
  "SzybkiRouter\n"
  "WiFiWulkan\n"
  "SamsungRouter\n"
  "OdKolegi\n"
  "WIFIIBM\n"
  "Chymel Jadwiga\n"
  "Router Marcina\n"
  "Pralka Siemens\n"
  "Czarny\n"
  "AntenaAsus\n"
  "Tata\n"
  "Mercedes\n"
  "Dziadek\n"
  "LTE+\n"
  "Działa W Tunelach\n"
  "Internet\n"
  "Google\n"
  "Polskie LTE\n"
  "WiFi 1TB\n"
  "Tata\n"
  "Lenovo\n"
  "Toschiba\n"
  "SamsungWiFi\n"
  "Xiaomi Mi Band 5\n"
  "WiFi Dla Rudych\n"
  "Działa przez ściany\n"
  "Modem Duży Pokój\n"
  "7289202900\n"
  "qwerty8800\n"
  "Z Wszechświata\n"
  "9865567889976543566\n"
  "Hakerzy\n"
  "MSK\n"
  "WiFiToshiba\n"
  "Międznarodowy\n"
  "Kabel mi urwiesz\n"
  "Miejskie\n"
  "WiFiZSamsung\n"
  "SuperInternet\n"
  "Kanalizacja\n"
  "SkrzynkaToshiba\n"
  "SzybkiRouter\n"
  "WiFiWulkan\n"
  "SamsungRouter\n"
  "OdKolegi\n"
  "WIFIIBM\n"
  "Chymel Jadwiga\n"
  "Router Marcina\n"
  "Pralka Siemens\n"
  "Czarny\n"
  "AntenaAsus\n"
  "Tata\n"
  "Mercedes\n"
  "Dziadek\n"
  "LTE+\n"
  "Działa W Tunelach\n"
  "Internet\n"
  "Google\n"
  "Polskie LTE\n"
  "WiFi 1TB\n"
  "Tata\n"
  "Lenovo\n"
  "Toschiba\n"
  "SamsungWiFi\n"
  "Xiaomi Mi Band 5\n"
  "WiFi Dla Rudych\n"
  "Działa przez ściany\n"
  "Modem Duży Pokój\n"
  "7289202900\n"
  "qwerty8800\n"
  "Z Wszechświata\n"
  "9865567889976543566\n"
  "Hakerzy\n"
  "MSK\n"
  "WiFiToshiba\n"
  "Międznarodowy\n"
  "Česká republika\n"
  "Vifon\n"
  "Piwo musi pit\n"
  "DE\n"
  "Po Kablu\n"
  "Na Zawsze\n"
  "Odkurzacz\n"
  "WiFi Zza Okna\n"
  "Sieć Xiaomi\n"
  "Rura\n"
  "Toyota\n"
  "Lenovo Legion\n"
  "Modem Orange\n"
  "Skrzynka Odbiorcza\n"
  "Samsung Internet\n"
  "Przychodnia\n"
  "Przyjaciele.pl\n"
  "United Kingdom\n"
  "Soviet Union\n"
  "Bez Zakłóceń\n"
  "Wspaniała Jakość\n"
  "如果你想学习中\n"
  "Za Chwilę Będę\n"
  "nuqneH! QaQ jajvam\n"
  "4566778\n"
  "IOT\n"
  "SkrzynkaToshiba\n"
  "Złota44\n"
  "Bez Zakłóceń\n"
  "SamsungWiFi\n"
  "Bezprzewodowy\n"
  "Stalinsoft\n"
  "Kosmici\n"
  "如果你想学习中文，我可以帮助你\n"
  "こんにちは！今日はいい\n"
  "Modem\n"
  "你好！希望你今天过得愉\n"
  "HotspotXiaomi\n"
  "Internet 5G\n"
  "Samsung\n"
  "SiećLaptopy\n"
  "Magik\n"
  "RouterWSieci\n" 
};

#include <ESP8266WiFi.h>

extern "C" {
#include "user_interface.h"
  typedef void (*freedom_outside_cb_t)(uint8 status);
  int wifi_register_send_pkt_freedom_cb(freedom_outside_cb_t cb);
  void wifi_unregister_send_pkt_freedom_cb(void);
  int wifi_send_pkt_freedom(uint8 *buf, int len, bool sys_seq);
}
char emptySSID[32];
uint8_t channelIndex = 0;
uint8_t macAddr[6];
uint8_t wifi_channel = 1;
uint32_t currentTime = 0;
uint32_t packetSize = 0;
uint32_t packetCounter = 0;
uint32_t attackTime = 0;
uint32_t packetRateTime = 0;

uint8_t beaconPacket[109] = {
  /*  0 - 3  */ 0x80, 0x00, 0x00, 0x00,            
  /*  4 - 9  */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  /* 10 - 15 */ 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
  /* 16 - 21 */ 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 

  /* 22 - 23 */ 0x00, 0x00,                        
  /* 24 - 31 */ 0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00,
  /* 32 - 33 */ 0xe8, 0x03,                         
  /* 34 - 35 */ 0x31, 0x00,           



  /* 36 - 37 */ 0x00, 0x20,                      
  /* 38 - 69 */ 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20,                      

  /* 70 - 71 */ 0x01, 0x08,       
  /* 72 */ 0x82,                  
  /* 73 */ 0x84,                   
  /* 74 */ 0x8b,                   
  /* 75 */ 0x96,                   
  /* 76 */ 0x24,                   
  /* 77 */ 0x30,                  
  /* 78 */ 0x48,                   
  /* 79 */ 0x6c,                   

  // Current Channel
  /* 80 - 81 */ 0x03, 0x01,         
  /* 82 */      0x01,           

  // RSN information
  /*  83 -  84 */ 0x30, 0x18,
  /*  85 -  86 */ 0x01, 0x00,
  /*  87 -  90 */ 0x00, 0x0f, 0xac, 0x02,
  /*  91 -  92 */ 0x02, 0x00,
  /*  93 - 100 */ 0x00, 0x0f, 0xac, 0x04, 0x00, 0x0f, 0xac, 0x04,
  /* 101 - 102 */ 0x01, 0x00,
  /* 103 - 106 */ 0x00, 0x0f, 0xac, 0x02,
  /* 107 - 108 */ 0x00, 0x00
};

void nextChannel() {
  if (sizeof(channels) > 1) {
    uint8_t ch = channels[channelIndex];
    channelIndex++;
    if (channelIndex > sizeof(channels)) channelIndex = 0;

    if (ch != wifi_channel && ch >= 1 && ch <= 14) {
      wifi_channel = ch;
      wifi_set_channel(wifi_channel);
    }
  }
}

// Random MAC generator
void randomMac() {
  for (int i = 0; i < 6; i++){
     macAddr[i] = random(256);
  }
}

void setup() {
  // create empty SSID
  for (int i = 0; i < 32; i++)
    emptySSID[i] = ' ';

  // for random generator
  randomSeed(os_random());

  // set packetSize
  packetSize = sizeof(beaconPacket);
  if (wpa2) {
    beaconPacket[34] = 0x31;
  } else {
    beaconPacket[34] = 0x21;
    packetSize -= 26;
  }

  randomMac();

  // start serial
  Serial.begin(115200);
  Serial.println();

  // get time
  currentTime = millis();

  // start WiFi
  WiFi.mode(WIFI_OFF);
  wifi_set_opmode(STATION_MODE);
  
  wifi_set_channel(channels[0]);

  Serial.println("SSIDs:");
  int i = 0;
  int len = sizeof(ssids);
  while (i < len) {
    Serial.print((char)pgm_read_byte(ssids + i));
    i++;
  }

  Serial.println();
  Serial.println("Started \\o/");
  Serial.println();
}

void loop() {
  currentTime = millis();

  if (currentTime - attackTime > 100) {
    attackTime = currentTime;

    int i = 0;
    int j = 0;
    int ssidNum = 1;
    char tmp;
    int ssidsLen = strlen_P(ssids);
    bool sent = false;

    nextChannel();

    while (i < ssidsLen) {
      j = 0;
      do {
        tmp = pgm_read_byte(ssids + i + j);
        j++;
      } while (tmp != '\n' && j <= 32 && i + j < ssidsLen);

      uint8_t ssidLen = j - 1;
      macAddr[5] = ssidNum;
      ssidNum++;

      memcpy(&beaconPacket[10], macAddr, 6);
      memcpy(&beaconPacket[16], macAddr, 6);
      memcpy(&beaconPacket[38], emptySSID, 32);
      memcpy_P(&beaconPacket[38], &ssids[i], ssidLen);
      
      beaconPacket[82] = wifi_channel;

      if (appendSpaces) {
        for (int k = 0; k < 3; k++) {
          packetCounter += wifi_send_pkt_freedom(beaconPacket, packetSize, 0) == 0;
          delay(1);
        }
      }
      else {

        uint16_t tmpPacketSize = (packetSize - 32) + ssidLen;
        uint8_t* tmpPacket = new uint8_t[tmpPacketSize]; 
        memcpy(&tmpPacket[0], &beaconPacket[0], 38 + ssidLen);
        tmpPacket[37] = ssidLen;
        memcpy(&tmpPacket[38 + ssidLen], &beaconPacket[70], wpa2 ? 39 : 13);

       
        for (int k = 0; k < 3; k++) {
          packetCounter += wifi_send_pkt_freedom(tmpPacket, tmpPacketSize, 0) == 0;
          delay(1);
        }

        delete tmpPacket;
      }

      i += j;
    }
  }
  if (currentTime - packetRateTime > 1000) {
    packetRateTime = currentTime;
    Serial.print("Packets/s: ");
    Serial.println(packetCounter);
    packetCounter = 0;
  }
}
//By Qbaa134
