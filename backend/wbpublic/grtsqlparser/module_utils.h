/* 
 * Copyright (c) 2007, 2016, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#pragma once

#include "wbpublic_public_interface.h"
#include "grt.h"

template<typename T1>
void overwrite_default_option(bool &value, const char *name, const grt::DictRef &options)
{
  if (options.is_valid() && options.has_key(name))
    value= T1::cast_from(options.get(name)) != 0;
}

template<typename T>
void overwrite_default_option(T &value, const char *name, const grt::DictRef &options, bool init_with_empty_value)
{
  if (options.is_valid() && options.has_key(name))
  {
    value= T::cast_from(options.get(name));
    if (init_with_empty_value && !value.is_valid())
      value= T();
  }
}
