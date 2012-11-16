#include "monitor.h"

static u16int cursor_y;
static u16int cursor_x;
static u16int *video_memory = (u16int *)0xB8000;

// Updates the hardware cursor.
static void move_cursor()
{
   // The screen is 80 characters wide...
   u16int cursorLocation = cursor_y * 80 + cursor_x;
   outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
   outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
   outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
   outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

// Scrolls the text on the screen up by one line.
static void scroll()
{

   // Get a space character with the default colour attributes.
   u8int attributeByte = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
   u16int blank = 0x20 /* space */ | (attributeByte << 8);

   // Row 25 is the end, this means we need to scroll up
   if(cursor_y >= 25)
   {
       // Move the current text chunk that makes up the screen
       // back in the buffer by a line
       int i;
       for (i = 0*80; i < 24*80; i++)
       {
           video_memory[i] = video_memory[i+80];
       }

       // The last line should now be blank. Do this by writing
       // 80 spaces to it.
       for (i = 24*80; i < 25*80; i++)
       {
           video_memory[i] = blank;
       }
       // The cursor should now be on the last line.
       cursor_y = 24;
   }
}

void monitor_put(char c)
{
  u8int backColor = 0;
  u8int foreColor = 15;

  u8int attrByte = (backColor << 4) | (foreColor & 0x0F);
  u16int attr = attrByte << 8;
  u16int *location;

  if (c == 0x08 /*backspace*/ && cursor_x)
    cursor_x--;
  else if (c == 0x09 /*tab space*/)
    cursor_x = (cursor_x+8) & ~(8-1);
  else if (c == '\r')
    cursor_x = 0;
  else if (c == '\n') {
    cursor_x = 0;
    cursor_y++;
  } else if (c >= ' ') {
    location = video_memory + (cursor_y*80 + cursor_x);
    *location = c | attr;
    cursor_x++;
  }

  if (cursor_x >= 80) {
    cursor_x = 0;
    cursor_y++;
  }

  scroll();
  move_cursor();
}

void monitor_clear()
{
  u8int attrByte = (0 << 4) | (15 & 0x0F);
  u16int blank = 0x20 | (attrByte << 8);

  int i;
  for (i = 0; i < 80*25; i++)
    video_memory[i] = blank;

  cursor_x = cursor_y = 0;
  move_cursor();
}
      
void monitor_write(char *c)
{
  int i = 0;
  while (c[i])
    monitor_put(c[i++]);
}
