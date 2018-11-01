/*
  class file for UtPod

*/

#include<iostream>
#include "UtPod.h"
#include "Song.h"

using namespace std;

  UtPod::UtPod()
  {
    memSize = MAX_MEMORY;
    songs = NULL;
  }

  UtPod::UtPod(int size)
  {
    if ( size > MAX_MEMORY || size <= 0 ){
      memSize = MAX_MEMORY;
    }else{
      memSize = size;
    }
    songs = NULL;
  }

  int UtPod::addSong(Song const &s)
  {
    if (s.getSize() > this->getRemainingMemory()){
      return NO_MEMORY;
    }
    SongNode *addSong = new SongNode;
    addSong->s = s;
    addSong->next = songs;
    songs = addSong;
    return SUCCESS;
  }
  
  int UtPod::removeSong(Song const &s)
  {
    return SUCCESS;

  }

  void UtPod::shuffle()
  {


  }

  void UtPod::showSongList()
  {



  }

  void UtPod::sortSongList()
  {
  
  
  }

  void UtPod::clearMemory()
  {


  }

  int UtPod::getRemainingMemory()
  {
    int remMem = 0;


    return remMem;
  }

  UtPod::~UtPod()
  {
    // cout << "In UtPod destructor" << endl;
  
  }
