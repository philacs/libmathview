// Copyright (C) 2000-2004, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://helm.cs.unibo.it/mml-widget/, or send a mail to
// <lpadovan@cs.unibo.it>

#include <config.h>

#include <cassert>

#include "libxml2_Builder.hh"
#include "libxml2_Model.hh"
#include "TemplateBuilder.hh"

libxml2_Builder::~libxml2_Builder()
{
  setRootModelElement(0);
}

SmartPtr<libxml2_Builder>
libxml2_Builder::create()
{ return TemplateBuilder<libxml2_Model>::create(); }

SmartPtr<Element>
libxml2_Builder::findSelfOrAncestorElement(xmlNode* el) const
{
  for (xmlNode* p = el; p; p = p->parent)
    if (SmartPtr<Element> elem = getLinker().assoc(libxml2_Model::asElement(p)))
      return elem;
  return 0;
}

xmlNode*
libxml2_Builder::findSelfOrAncestorModelNode(const SmartPtr<Element>& elem) const
{
  for (SmartPtr<Element> p(elem); p; p = p->getParent())
    if (xmlElement* el = getLinker().assoc(p))
      return (xmlNode*) el;
  return 0;
}

void
libxml2_Builder::setRootModelElement(xmlElement* el)
{
  root = el;
}