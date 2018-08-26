#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compare(const struct Segment & seg1, const struct Segment & seg2)
{
	return seg1.start < seg2.start;
}

bool check_overlap()
{

}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  // thinking of a sorted stack approach, prio q.
  // where we pop off segments after we've found a point that hits whatever.
  std::sort(segments.begin(), segments.end(), compare);
  std::vector<bool>is_covered;
  for (int i = 0; i < segments.size(); ++i)
  {
	  is_covered.push_back(false);
  }

  bool done = false;
  // standard for loop fails...unless worst case scenario
  int num_segs = segments.size();
  int sdx = 0, curr_pt = 0;
  while (!done)
  {
	  // we are done when each segment contains at least one point,
	  // at which point is_covered will be all true
	  // walk through the current segment until we get to its end
	  // essentially trying to maximuze the number of overlaps.
	  // how to detect an overlap? basically bounds checking. can we add stuff to sets?
	  // algo is to assign a point as late as possible, it seems
	  curr_pt = segments.at(sdx).start;
	  dx      = 1;
	  // walk forward until...
	  while (curr_pt + dx <= segments.at(sdx).end)
	  {

	  }
	  if ()
	  {
		  points.push_back(curr_pt);
	  }
	  ++curr_pt;
  }
  
/*
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
