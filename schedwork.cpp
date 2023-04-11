#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#endif

// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool solver(size_t current_day, size_t current_worker, size_t maxShifts, size_t dailyNeed, DailySchedule& sched, const AvailabilityMatrix& avail, std::vector<int>shifts );

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below
    //d= needed and required; k =nurses present; n =time period
    //workers cannot work more than m maxShifts in n time period
    //with d, m, and k schedule nurses
    //int total_workers=avail[0].size();
    unsigned int total_days=avail.size();
    //how do we know when we are finished 
    //base case: when all days have d workers
    //ie when every space in sched has a valid worker
    for (size_t i =0; i<total_days; i++ ){
        sched.push_back(std::vector<Worker_T>(dailyNeed, INVALID_ID));
        
    }
    std::vector<int>shifts(avail[0].size(), 0);

    size_t current_day=0;
    size_t current_worker=0;
    
   return solver(current_day, current_worker, maxShifts, dailyNeed, sched, avail, shifts);

    




}
bool solver(size_t current_day, size_t current_worker, size_t maxShifts, size_t dailyNeed, DailySchedule& sched, const AvailabilityMatrix& avail, std::vector<int>shifts ){
  if (current_day==sched.size()){
        return true;
    }
  if (current_worker==dailyNeed){
    return solver(current_day+1, 0, maxShifts, dailyNeed, sched, avail, shifts );
  }
  for (unsigned int i=0; i< avail[current_day].size();i++ ){
    if (avail[current_day][i]==1 && shifts[i]< maxShifts){
      sched[current_day][current_worker]=i;
      shifts[i]++;
      if (solver(current_day, current_worker+1, maxShifts, dailyNeed, sched, avail, shifts)){
        return true;
      }
      else{
        sched[current_day][current_worker]=INVALID_ID;
        shifts[i]--;
        //return false;
      }

    }
  }
  return false;
  
}



