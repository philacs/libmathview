// Copyright (C) 2000-2003, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://helm.cs.unibo.it/mml-widget, or send a mail to
// <luca.padovani@cs.unibo.it>

#include <config.h>

#include <cassert>

#include "ShapingResult.hh"

unsigned
ShapingResult::chunkSize() const
{
  assert(!done());
  unsigned n = 0;
  unsigned si = getShaperId();
  while (index + n < spec.size() && spec[index + n].getShaperId() == si) n++;
  return n;
}

unsigned
ShapingResult::getShaperId() const
{
  assert(!done());
  return spec[index].getShaperId();
}

const DOM::Char32*
ShapingResult::data() const
{
  assert(!done());
  return source.data() + index;
}

AreaRef
ShapingResult::area() const
{
  if (res.size() == 1)
    return res[0];
  else
    return factory->createHorizontalArrayArea(res);
}

void
ShapingResult::advance(int n)
{
  assert(index + n >= 0 && index + n <= source.length());
  index += n;
}

DOM::Char32
ShapingResult::prevChar() const
{
  assert(index > 0);
  return source[index - 1];
}

DOM::Char32
ShapingResult::nextChar() const
{
  assert(index < source.length());
  return source[index];
}

DOM::UCS4String
ShapingResult::prevString(int l) const
{
  if (l < 0 || l > index) l = index;
  return source.substr(index - l, l);
}

DOM::UCS4String
ShapingResult::nextString(int l) const
{
  if (l < 0 || l > source.length() - index) l = source.length() - index;
  return source.substr(index, l);
}

