// Copyright (C) 2000-2007, Luca Padovani <padovani@sti.uniurb.it>.
//
// This file is part of GtkMathView, a flexible, high-quality rendering
// engine for MathML documents.
// 
// GtkMathView is free software; you can redistribute it and/or modify it
// either under the terms of the GNU Lesser General Public License version
// 3 as published by the Free Software Foundation (the "LGPL") or, at your
// option, under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation (the "GPL").  If you do not
// alter this notice, a recipient may use your version of this file under
// either the GPL or the LGPL.
//
// GtkMathView is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the LGPL or
// the GPL for more details.
// 
// You should have received a copy of the LGPL and of the GPL along with
// this program in the files COPYING-LGPL-3 and COPYING-GPL-2; if not, see
// <http://www.gnu.org/licenses/>.

#include <config.h>

#include <string>
#include <sstream>

#include <cassert>

#include "LengthAux.hh"

static const char* unitName[] = {
  "??",
  "",
  "infinity",
  "lt",
  "em",
  "ex",
  "px",
  "in",
  "cm",
  "mm",
  "pt",
  "pc",
  "%",
  "negativeveryverythickspace",
  "negativeverythickspace",
  "negativethickspace",
  "negativemediumspace",
  "negativethinspace",
  "negativeverythinspace",
  "negativeveryverythinspace",
  "zerospace",
  "veryverythinspace",
  "verythinspace",
  "thinspace",
  "mediumspace",
  "thickspace",
  "verythickspace",
  "veryverythickspace",
  nullptr
};

std::string
toString(Length::Unit unit)
{
  assert(unit >= Length::UNDEFINED_UNIT && unit < Length::LAST_UNIT);
  return unitName[unit];
}

bool
fromString(const std::string& s, Length::Unit& unit)
{
  for (unsigned i = 0; unitName[i]; i++)
    if (s == unitName[i])
      {
	unit = Length::Unit(i);
	return true;
      }
  return false;
}

std::ostream&
operator<<(std::ostream& os, const Length::Unit& unit)
{ return os << toString(unit); }

std::string
toString(const Length& length)
{
  if (!length.defined())
    return "[undefined length]";
  if (length.isSpace())
    return unitName[length.type];
  else if (length.type == Length::INFINITY_UNIT)
    return (length.value < 0.0) ? "-infinity" : "infinity";
  else
    {
      std::ostringstream os;
      os << length.value << length.type;
      return os.str();
    }
}

std::ostream&
operator<<(std::ostream& os, const Length& length)
{ return os << toString(length); }


