//
// A simple CS Coin miner program for CS 4000, Homework #5
//
// The program reads in two big integers l and r, and stores them in the
// boost data structure cpp_int.
//
// This CS Coin miner starts at 0 and iteratively tries all integers until
// it finds an integer z such that l < shar256(z) < r.
// It then outputs z and quits.
//
// Written by David W. Juedes, April 9th, 2021.
//
//

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <cassert>
#include <thread>
using namespace std;
using namespace boost::multiprecision;

cpp_int t1;
cpp_int t2;

bool stop = true;

//
// Function: to_bits
// Converts a cpp_int x into a vector of unsigned characters (8-bit ints).
//
//
vector<unsigned char> to_bits(cpp_int x) {
  unsigned char c;

  vector<unsigned char> buffer;
  while (x>0) {
    c = (unsigned char) x%256;
    buffer.push_back(c);
    x=x/256;
  }

  return buffer;
}

//
// Function sha256(x)
// Applies the standard sha256 algorithm from openssl to a cpp_int.
// Returns the corresponding cpp_int.
// Note: SHA256_DIGEST_LENGTH is 32.
// (8*32 = 256).
//
cpp_int sha256(const cpp_int x)
{
  vector<unsigned char> int_buffer;
  int_buffer = to_bits(x);
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256(&int_buffer[0],int_buffer.size(),hash);
  cpp_int total = 0;
  for (int i=0;i<SHA256_DIGEST_LENGTH;i++) {
    total = total*256+(int) hash[i];
  }

  return total;
}

void quad_sha0(int p, int round){
  cpp_int cpp_round = (cpp_int)round;
  cpp_int t = 0;
  cpp_int next_sha;
  int i;
  //
  // cout<<"size of cpp round: "<< cpp_round.size()<<endl;
  // cout<<"size of cpp t: "<< t.size()<<endl;

  switch(p){
    case 0:
      t = (cpp_round - (cpp_int)100000);
      i = ((int)t + 25000);
    break;
    case 1:
      t = (cpp_round - (cpp_int)75000);
      i = ((int)t + 25000);
    break;
    case 2:
      t = (cpp_round - (cpp_int)50000);
      i = ((int)t + 25000);
      break;
    case 3:
      t = (cpp_round - (cpp_int)25000);
      i = ((int)t + 25000);
    break;
  }

  bool found = false;
  while (!found && stop == true) {

    next_sha = sha256(t);
    if (t1 < next_sha) {
      if (next_sha < t2) {
	//cerr << next_sha << endl;
	cout << t << endl;
	found = true;
  stop  = false;
      }
    }
    t =t+1;

    if(t==i){
      cpp_round +=100000;
      switch(p){
        case 0:
          t = (cpp_round - (cpp_int)100000);
          i = ((int)t + 25000);
        break;
        case 1:
          t = (cpp_round - (cpp_int)75000);
          i = ((int)t + 25000);
        break;
        case 2:
          t = (cpp_round - (cpp_int)50000);
          i = ((int)t + 25000);
          break;
        case 3:
          t = (cpp_round - (cpp_int)25000);
          i = ((int)t + 25000);
        break;
      }
    }

  }
}

void quad_sha1(int p, int round){
  cpp_int cpp_round = (cpp_int)round;
  cpp_int t = 0;
  cpp_int next_sha;
  int i;
  //
  // cout<<"size of cpp round: "<< cpp_round.size()<<endl;
  // cout<<"size of cpp t: "<< t.size()<<endl;

  switch(p){
    case 0:
      t = (cpp_round - (cpp_int)100000);
      i = ((int)t + 25000);
    break;
    case 1:
      t = (cpp_round - (cpp_int)75000);
      i = ((int)t + 25000);
    break;
    case 2:
      t = (cpp_round - (cpp_int)50000);
      i = ((int)t + 25000);
      break;
    case 3:
      t = (cpp_round - (cpp_int)25000);
      i = ((int)t + 25000);
    break;
  }

  bool found = false;
  while (!found && stop == true) {
    //cout<<"T: "<<t<<endl;
    next_sha = sha256(t);
    if (t1 < next_sha) {
      if (next_sha < t2) {
	//cerr << next_sha << endl;
	cout << t << endl;
	found = true;
  stop  = false;
      }
    }
    t =t+1;

    if(t==i){
      cpp_round +=100000;
      switch(p){
        case 0:
          t = (cpp_round - (cpp_int)100000);
          i = ((int)t + 25000);
        break;
        case 1:
          t = (cpp_round - (cpp_int)75000);
          i = ((int)t + 25000);
        break;
        case 2:
          t = (cpp_round - (cpp_int)50000);
          i = ((int)t + 25000);
          break;
        case 3:
          t = (cpp_round - (cpp_int)25000);
          i = ((int)t + 25000);
        break;
      }
    }

  }
}

void quad_sha2(int p, int round){
  cpp_int cpp_round = (cpp_int)round;
  cpp_int t = 0;
  cpp_int next_sha;
  int i;
  //
  // cout<<"size of cpp round: "<< cpp_round.size()<<endl;
  // cout<<"size of cpp t: "<< t.size()<<endl;

  switch(p){
    case 0:
      t = (cpp_round - (cpp_int)100000);
      i = ((int)t + 25000);
    break;
    case 1:
      t = (cpp_round - (cpp_int)75000);
      i = ((int)t + 25000);
    break;
    case 2:
      t = (cpp_round - (cpp_int)50000);
      i = ((int)t + 25000);
      break;
    case 3:
      t = (cpp_round - (cpp_int)25000);
      i = ((int)t + 25000);
    break;
  }

  bool found = false;
  while (!found && stop == true) {
    //cout<<"T: "<<t<<endl;
    next_sha = sha256(t);
    if (t1 < next_sha) {
      if (next_sha < t2) {
	//cerr << next_sha << endl;
	cout << t << endl;
	found =true;
  stop = false;
      }
    }
    t =t+1;

    if(t==i){
      cpp_round +=100000;
      switch(p){
        case 0:
          t = (cpp_round - (cpp_int)100000);
          i = ((int)t + 25000);
        break;
        case 1:
          t = (cpp_round - (cpp_int)75000);
          i = ((int)t + 25000);
        break;
        case 2:
          t = (cpp_round - (cpp_int)50000);
          i = ((int)t + 25000);
          break;
        case 3:
          t = (cpp_round - (cpp_int)25000);
          i = ((int)t + 25000);
        break;
      }
    }

  }
}

void quad_sha3(int p, int round){
  cpp_int cpp_round = (cpp_int)round;
  cpp_int t = 0;
  cpp_int next_sha;
  int i;
  //
  // cout<<"size of cpp round: "<< cpp_round.size()<<endl;
  // cout<<"size of cpp t: "<< t.size()<<endl;

  switch(p){
    case 0:
      t = (cpp_round - (cpp_int)100000);
      i = ((int)t + 25000);
    break;
    case 1:
      t = (cpp_round - (cpp_int)75000);
      i = ((int)t + 25000);
    break;
    case 2:
      t = (cpp_round - (cpp_int)50000);
      i = ((int)t + 25000);
      break;
    case 3:
      t = (cpp_round - (cpp_int)25000);
      i = ((int)t + 25000);
    break;
  }

  bool found = false;
  while (!found && stop == true ) {
    //cout<<"T: "<<t<<endl;
    next_sha = sha256(t);
    if (t1 < next_sha) {
      if (next_sha < t2) {
	//cerr << next_sha << endl;
	cout << t << endl;
	found =true;
  stop = false;
      }
    }
    t =t+1;

    if(t==i){
      cpp_round +=100000;
      switch(p){
        case 0:
          t = (cpp_round - (cpp_int)100000);
          i = ((int)t + 25000);
        break;
        case 1:
          t = (cpp_round - (cpp_int)75000);
          i = ((int)t + 25000);
        break;
        case 2:
          t = (cpp_round - (cpp_int)50000);
          i = ((int)t + 25000);
          break;
        case 3:
          t = (cpp_round - (cpp_int)25000);
          i = ((int)t + 25000);
        break;
      }
    }

  }
}

int main() {

  cin >> t1;
  cin >> t2;
  assert(t1 < t2);

  // init stuff for threads
  int round = 100000;

  int p = 0;
  thread thread0(quad_sha0, p, round);
  p = p+1;
  thread thread1(quad_sha1, p, round);
  p = p+2;
  thread thread2(quad_sha2, p, round);
  p = p+3;
  thread thread3(quad_sha3, p, round);

  thread0.join();
  thread1.join();
  thread2.join();
  thread3.join();

  //cout<<"continuing with round..."<<round<<endl;
  // thread1.join();
  // thread2.join();
  // thread3.join();

  //
  // cpp_int t = 0;
  // cpp_int next_sha;
  // bool found = false;
  // while (!found) {
  //   next_sha = sha256(t);
  //   if (t1 < next_sha) {
  //     if (next_sha < t2) {
	// //cerr << next_sha << endl;
	// cout << t << endl;
	// found =true;
  //     }
  //   }
  //   t=t+1;
  // }

}
