#ifndef OSMSCOUT_MAP_SIMPLIFIEDPATH_H
#define OSMSCOUT_MAP_SIMPLIFIEDPATH_H

/*
  This source is part of the libosmscout-map library
  Copyright (C) 2017 Lukas Karas

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

#include <osmscout/MapImportExport.h>
#include <osmscout/Pixel.h>

#include <vector>

namespace osmscout {
  struct Segment
  {
    Vertex2D start;
    double offset;
    double length;
    double angle;
  };

  class OSMSCOUT_MAP_API LabelPath
  {
  private:
    double length;
    std::vector<Segment> segments;
    std::vector<size_t> offsetIndex; // segment offset by length 100
    double minSegmentLength;
    Vertex2D end;
    double endDistance;

  public:
    LabelPath(double minSegmentLength=5);
    virtual ~LabelPath();
    void AddPoint(double x,double y);
    inline double GetLength() const {
      return length+endDistance;
    }
    Vertex2D PointAtLength(double offset) const;
    double AngleAtLength(double offset) const;
    double AngleAtLengthDeg(double offset) const;

    bool TestAngleVariance(double startOffset, double endOffset, double maximumAngle) const;
  private:
    const Segment& segmentBefore(double offset) const;
  };
}

#endif /* OSMSCOUT_MAP_SIMPLIFIEDPATH_H */
