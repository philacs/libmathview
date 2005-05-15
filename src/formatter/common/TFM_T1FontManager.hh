// Copyright (C) 2000-2005, Luca Padovani <luca.padovani@cs.unibo.it>.
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

#ifndef __TFM_T1FontManager_hh__
#define __TFM_T1FontManager_hh__

#include "Object.hh"
#include "String.hh"
#include "HashMap.hh"
#include "SmartPtr.hh"
#include "scaled.hh"

class TFM_T1FontManager : public Object
{
protected:
  TFM_T1FontManager(const SmartPtr<class TFMManager>&);
  virtual ~TFM_T1FontManager();

public:
  static SmartPtr<TFM_T1FontManager> create(const SmartPtr<class TFMManager>&);

  SmartPtr<class TFM_T1Font> getT1Font(const String&, const scaled&) const;

protected:
  virtual SmartPtr<class TFM_T1Font> createT1Font(const String&, const scaled&) const;

private:
  struct CachedT1FontKey
  {
    CachedT1FontKey(const String& n, const scaled& sz)
      : name(n), size(sz) { }
    
    bool operator==(const CachedT1FontKey& key) const
    { return name == key.name && size == key.size; }
    
    String name;
    scaled size;
  };

  struct CachedT1FontHash
  {
    size_t operator()(const CachedT1FontKey& key) const
    { return StringHash()(key.name) ^ key.size.getValue(); }
  };

  typedef HASH_MAP_NS::hash_map<CachedT1FontKey,SmartPtr<class TFM_T1Font>,CachedT1FontHash> T1FontCache;
  mutable T1FontCache fontCache;
  SmartPtr<class TFMManager> tfmManager;
};

#endif // __TFM_T1FontManager_hh__