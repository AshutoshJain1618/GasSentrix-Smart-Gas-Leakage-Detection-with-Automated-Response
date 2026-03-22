#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Nothing2";
const char* password = "password";

String botToken = "7921523717:AAFKMFDkdkKNqjTXk5jb1BBiX5O_HtYCF4s";
String chatID = "8471108590";

#define GAS_DO     27
#define GREEN_LED  14
#define RED_LED    13
#define BUZZER     26

bool alertSent = false;

void setup() {
  Serial.begin(115200);

  pinMode(GAS_DO, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  // Connect WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.println(WiFi.localIP());
}

// Telegram bot
void sendTelegram(String message) {
  HTTPClient http;
  String url = "https://api.telegram.org/bot" + botToken +
               "/sendMessage?chat_id=" + chatID +
               "&text=" + message;

  http.begin(url);
  http.GET();
  http.end();
}

void loop() {
  int gasState = digitalRead(GAS_DO);
  Serial.print("Gas State: ");
  Serial.println(gasState);

  if (gasState == HIGH) {
    
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
    alertSent = false;
  } 
  else {
    
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
    delay(300);

    if (!alertSent) {
      sendTelegram("GAS LEAK DETECTED! Please take immediate action.");
      alertSent = true;
    }
  }
}
