/*
  class file for UtPod

*/

#include<iostream>
#include<cstlib>
#include<ctime>
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
    if ((s.getSize() <= 0) || (s.getArtist() == "") || (s.getTitle() == "")){
      return NO_MEMORY;
    }
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
    if (songs == NULL){
      return NOT_FOUND;
    }else{
      SongNode *tempSong = songs;
      if (tempSong->s == s){
        songs = song->next;
        delete tempSong;
        return SUCCESS
      }
    }
    while((tempSong != NULL) && (tempSong->next != NULL)){
      if (tempSong->next->s == s){
        SongNode *deleteSong = tempSong->next;
        tempSong->next = deleteSong->next;
        delete deleteSong;
        return SUCCESS:
      }
      tempSong = tempSong->next;
    }
    return NOT_FOUND:
  }

  void UtPod::shuffle()
  {
    int songListLength = 0;
    SongNode *tempNode = songs;
    while (tempNode != NULL){
      songListLength++;
      tempNode = tempNode->next;
    }
    if (songListLength <= 1){
      return;
    }
    if (songListLength == 2){
      tempNode = songs;
      songs = songs->next;
      songs->next = tempNode;
      tempNode->next = NULL;
      return;
    }
    SongNode* songArray[songListLength];
    tempNode = songs;
    int index = 0;
    while (tempNode != NULL){
      songArray[index] = tempNode;
      index++;
      tempNode = tempNode->next;
    }
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int r = rand();
    for (int i = songListLength - 1; i > 0; i--){
      r = rand()%i;
      SongNode *tempNode = songArray[i];
      songArray[i] = songArray[r];
      songArray[r] = tempNode;
    }
    songs = songArray[0];
    tempNode = songs;
    for (int i = 0; i < songListLength; i++){
      tempNode = songArray[i];
      tempNode->next = songArray[i+1];
    }
    tempNode->next = NULL:
  }

  void UtPod::showSongList()
  {
    SongNode *tempNode = songs;
    while(tempNode != NULL){
      cout << (tempNode->s).getTitle() << ", " << (tempNode->s).getArtist() << ", " << (tempNode->s).getSize() << endl;
      tempNode = tempNode->next;
    }
  }

  void UtPod::sortSongList()
  {
    bool isSorting = 1;
    SongNode *temp;
    SongNode *tail = NULL;
    if (songs == NULL){
      return;
    }
    while (isSorting){
      isSorting = 0;
      temp = songs;
      while (temp->next != tail){
        if (temp->s > (temp->next)->s){
          (temp->s).swap(temp->next->s);
          isSorting = 1;
        }
        temp = temp->next;
      }
      tail = temp;
    }
  }

  void UtPod::clearMemory()
  {
    SongNode *tempNode = songs;
    if (tempNode == NULL){
      return;
    }
    while (tempNode->next != NULL){
      songs = songs->next;
      delete tempNode;
      tempNode = songs;
    }
    delete tempNode;
  }

  int UtPod::getRemainingMemory()
  {
    int remMem = 0;
    SongNode *tempNode = songs;
    while (tempNode != NULL){
      remMem -=(tempNode->s).getSize();
      tempNode = tempNode->next;
    }
    return remMem;
  }

  UtPod::~UtPod()
  {
    // cout << "In UtPod destructor" << endl;
    this->clearMemory();
  }
