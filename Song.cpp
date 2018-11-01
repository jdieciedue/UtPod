/*


*/

#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

  Song::Song()
  {
    songTitle = NO_TITLE;
    songArtist = NO_ARTIST;
    songSize = MIN_SONG_SIZE;
  }

  Song::Song(string artist, string title)
  {
    songArtist = artist;
    songTitle = title;
    songSize = MIN_SONG_SIZE;
  }

  Song::Song(string artist, string title, int size)
  {
    songArtist = artist;
    songTitle = title;
    songSize = size;
  }

  string Song::getTitle() const
  {
    return songTitle;
  }

  void Song::setTitle(string title)
  {
    songTitle = title;
  }

  string Song::getArtist() const
  {
    return songArtist;
  }

  void Song::setArtist(string artist)
  {
    songArtist = artist;
  }

  int Song::getSize() const
  {
    return songSize;
  }

  void Song::setSize(int size)
  {
    songSize = size;
  }

  bool Song::operator >(Song const &rhs)
  {
    if (songArtist.compare(rhs.songArtist) < 0){
      return false;
    }else{
      if (songArtist.compare(rhs.songArtist) > 0){
        return true;
      }else{
        if(songTitle.compare(rhs.songTitle) < 0){
          return false;
        }else{
          if (songTitle.compare(rhs.songTitle) > 0){
            return true;
          }else{
            return (songSize > rhs.songSize);
          }
        }
      }
    }
  }

  bool Song::operator <(Song const &rhs)
  {
    if (songArtist.compare(rhs.songArtist) > 0){
      return false;
    }else{
      if (songArtist.compare(rhs.songArtist) < 0){
        return true;
      }else{
        if(songTitle.compare(rhs.songTitle) > 0){
          return false;
        }else{
          if (songTitle.compare(rhs.songTitle) < 0){
            return true;
          }else{
            return (songSize < rhs.songSize);
          }
        }
      }
    }
  }

  bool Song::operator ==(Song const &rhs)
  {
    return (songArtist == rhs.songArtist && 
            songTitle == rhs.songTitle && 
            songSize == rhs.songSize);
  }

  Song::~Song()
  {
   // cout << "In Song destructor" << endl;
  }

