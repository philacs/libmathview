// Copyright (C) 2000, Luca Padovani <luca.padovani@cs.unibo.it>.
// 
// This file is part of GtkMathView, a Gtk widget for MathML.
// 
// GtkMathView is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// GtkMathView is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GtkMathView; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
// 
// For details, see the GtkMathView World-Wide-Web page,
// http://cs.unibo.it/~lpadovan/mml-widget, or send a mail to
// <luca.padovani@cs.unibo.it>

#ifndef Rectangle_hh
#define Rectangle_hh

#include "scaled.hh"
#include "BoundingBox.hh"

struct Rectangle {
  scaled x;
  scaled y;
  scaled width;
  scaled height;

  Rectangle(void) { }
  Rectangle(const scaled& x0, const scaled& y0, const BoundingBox& box)
    : x(x0), y(y0 - box.height), width(box.width), height(box.verticalExtent()) { }

  void Zero(void) { x = y = width = height = 0; }

  bool Overlaps(const Rectangle& rect) const {
    return Overlaps(rect.x, rect.y, rect.width, rect.height);
  }

  bool Overlaps(const scaled& x0, const scaled& y0, const scaled& w0, const scaled& h0) const
  { return x <= x0 + w0 && x + width >= x0 && y <= y0 + h0 && y + height >= y0; }

  bool IsNull(void) const { return (width == scaled(0)) || (height == scaled(0)); }

  bool IsInside(const scaled& x0, const scaled& y0) const
  { return x <= x0 && x0 <= x + width && y <= y0 && y0 <= y + height; }

  void Union(const Rectangle&);

  void Dump(void) const;
};

#endif
