#include <iostream>
#include <vector>

using namespace std;

// Pseudocode:
// Compare slots starting at earliest.
// When comparing two slots:
//  if the slots do not overlap, then advance the slot with the lower start time.
//  if the slots overlap, then overlap_duration = min(end_timeA, end_timeB) - max(start_timeA, start_timeB)
//    if overlap_duration >= dur, then 
//      overlap_start = max(start_timeA, start_timeB)
//      return [overlap_start, overlap_start + dur]
//    else
//      advance the slot with the lower start time

// Assume slotsA has length A, slotB has length B
// Time: O(A+B)
// Space: O(1)

bool slots_overlap(const vector<int>& a, const vector<int>& b)
{
  return (a[1] > b[0] && b[1] > a[0]);
}

void advanceSlot(vector<vector<int>>::const_iterator& itA, vector<vector<int>>::const_iterator& itB)
{
  if ((*itA)[1] < (*itB)[1])
  {
    itA++;
  }
  else
  {
    itB++;
  }
}

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
  vector<vector<int>>::const_iterator itA = slotsA.begin();
  auto itB = slotsB.begin();
  
  while (itA != slotsA.end() && itB != slotsB.end())
  {
    auto slotA = *itA;
    auto slotB = *itB;
    
    if (slots_overlap(slotA, slotB))
    {
      int overlap_start = max(slotA[0], slotB[0]);
      int overlap_end = min(slotA[1], slotB[1]);
      
      int overlap_duration = overlap_end - overlap_start;
      
      if (overlap_duration >= dur)
      {
        return {overlap_start, overlap_start + dur};
      }
      else
      {
        advanceSlot(itA, itB);
      }
    }
    else
    {
      advanceSlot(itA, itB);
    }
  }
  
  return {};
}

int main() 
{
  auto output = meetingPlanner({{10, 50}, {60, 120}, {140, 210}}, {{0, 15}, {60, 70}}, 8);
  
  if (output.empty())
  {
    cout << "null" << endl;
  }
  else
  {
    cout << output[0] << ',' << output[1] << endl;
  }
  
  return 0;
}
