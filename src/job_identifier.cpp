// ---------------------------------------------------------------------
//
// Copyright (C) 1998 - 2017 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------

#include "job_identifier.h"
#include <ctime>


JobIdentifier dealjobid;


JobIdentifier::JobIdentifier()
{
  time_t t = std::time(nullptr);
  id = std::string("JobId ");

  id += std::string("unknown ");

  id += std::string(std::ctime(&t));
}


const std::string
JobIdentifier::operator ()() const
{
  return id;
}


std::string
JobIdentifier::base_name(const char *filename)
{
  std::string name(filename);
  std::string::size_type pos;
  pos = name.rfind('/');
  if (pos != std::string::npos)
    name.erase(0, pos + 1);
  pos = name.rfind('.');
  if (pos != std::string::npos)
    name.erase(pos, name.size());
  return name;
}