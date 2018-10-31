#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {
  private:
   string songTitle;
   string songArtist;
   int songSize;

   static const string NO_TITLE = "TITLE";
   static const string NO_ARTIST = "ARTIST";
   static const int MIN_SONG_SIZE = 1;

  public:
   Song();
   Song(string title, string artist);
   Song(string title, string artist, int size);

   string getTitle() const;
   void setTitle(string title);
   string getArtist() const;
   void setArtist(string artist);
   int getSize() const;
   void setSize(int size);

   bool operator >(Song const &rhs);
   bool operator <(Song const &rhs);
   bool operator ==(Song const &rhs);

   ~Song();
};

#endif