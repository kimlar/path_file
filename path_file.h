//
// File name and path functions utilities
//
// Author:	Kim Einar Larsen
// Email:	kim.developer@gmail.com
// Github:	https://github.com/kimlar
// Copyright (c) 2024 Kim Einar Larsen. All rights reserved.
//
// 
// NOTE: Since this path file utility is made for Windows,
//       the newline character is \r\n instead of \n.
// NOTE: Remember to use functions in pair tandum with *__new(..) and *__delete(..)
//
// TODO: Make this also to work with C++.
//
// Example:
//
//		#include "path_file.h"
//		...
//		str filename = "Temp/Resource.pack";
//		
//		str get_path = path_file_get_path__new(filename);					// Returns: Temp
//		str get_path_slash = path_file_get_path_slash__new(filename);		// Returns: Temp/
//		str get_fullname = path_file_get_fullname__new(filename);			// Returns: Resource.pack
//		str get_basename = path_file_get_basename__new(filename);			// Returns: Resource
//		str get_extension = path_file_get_extension__new(filename);			// Returns: pack
//		str get_extension_dot = path_file_get_extension_dot__new(filename);	// Returns: .pack
//		
//		printf("%s\n", get_path);
//		printf("%s\n", get_path_slash);
//		printf("%s\n", get_fullname);
//		printf("%s\n", get_basename);
//		printf("%s\n", get_extension);
//		printf("%s\n", get_extension_dot);
//		
//		path_file_get_path__delete(get_path);
//		path_file_get_path_slash__delete(get_path_slash);
//		path_file_get_fullname__delete(get_fullname);
//		path_file_get_basename__delete(get_basename);
//		path_file_get_extension__delete(get_extension);
//		path_file_get_extension_dot__delete(get_extension_dot);
// 
//

#pragma once

// Disable warnings
#define _CRT_SECURE_NO_WARNINGS

//
// C includes
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//
// Data types
//
typedef long long		i64;
typedef unsigned char*	str;

//
// Prototypes
//

str path_file_get_path__new(str filename);			// Returns: Temp
void path_file_get_path__delete(str self);
str path_file_get_path_slash__new(str filename);	// Returns: Temp/
void path_file_get_path_slash__delete(str self);
str path_file_get_fullname__new(str filename);		// Returns: Resource.pack
void path_file_get_fullname__delete(str self);
str path_file_get_basename__new(str filename);		// Returns: Resource
void path_file_get_basename__delete(str self);
str path_file_get_extension__new(str filename);		// Returns: pack
void path_file_get_extension__delete(str self);
str path_file_get_extension_dot__new(str filename);	// Returns: .pack
void path_file_get_extension_dot__delete(str self);

/* 
*	This function returns the path of the filename. Returns: Temp
*	Note: Returns a null pointer if the filename is NULL or empty string.
*	Note: The returned string must be freed by the caller.
*/
str path_file_get_path__new(str filename)
{
	assert(filename != NULL);
	assert(filename != "");
	if (filename == NULL || filename == "")
		return NULL; // Incorrect filename, returning a null pointer.

	// Find the last slash in the filename
	i64 last_slash = 0;
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '/' || filename[i] == '\\')
			last_slash = i;
	}

	// Create a string for the path to be returned
	str path = (str)malloc(last_slash + 1);

	// If it failed to allocate memory
	if(!path)
		return NULL;

	// Copy the path
	for (i64 i = 0; i < last_slash; i++)
	{
		path[i] = filename[i];
	}
	path[last_slash] = '\0';

	return path;
}
void path_file_get_path__delete(str self)
{
	free(self);
	self = NULL;
}

/*
*	This function returns the path (including the last slash) of the filename. Returns: Temp/
*	Note: Returns a null pointer if the filename is NULL or empty string.
*	Note: The returned string must be freed by the caller.
*/
str path_file_get_path_slash__new(str filename)
{
	assert(filename != NULL);
	assert(filename != "");
	if (filename == NULL || filename == "")
		return NULL; // Incorrect filename, returning a null pointer.

	// Find the last slash in the filename
	i64 last_slash = 0;
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '/' || filename[i] == '\\')
			last_slash = i + 1;
	}

	// Create a string for the path to be returned
	str path = (str)malloc(last_slash + 1);

	// If it failed to allocate memory
	if (!path)
		return NULL;

	// Copy the path
	for (i64 i = 0; i < last_slash; i++)
	{
		path[i] = filename[i];
	}
	path[last_slash] = '\0';

	return path;
}
void path_file_get_path_slash__delete(str self)
{
	free(self);
	self = NULL;
}

/*
*	This function returns the full filename (no path included). Returns: Resource.pack
*	Note: Returns a null pointer if the filename is NULL or empty string.
*	Note: The returned string must be freed by the caller.
*/
str path_file_get_fullname__new(str filename)
{
	assert(filename != NULL);
	assert(filename != "");
	if (filename == NULL || filename == "")
		return NULL; // Incorrect filename, returning a null pointer.

	// Find the last slash in the filename
	i64 last_slash = 0;
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '/' || filename[i] == '\\')
			last_slash = i + 1;
	}

	// Create a string for the full file name to be returned
	i64 fullname_length = (i64)strlen(filename) - last_slash;
	str fullname = (str)malloc(fullname_length + 1);

	// If it failed to allocate memory
	if (!fullname)
		return NULL;

	// Copy the fullname
	for (i64 i = 0; i < fullname_length; i++)
	{
		fullname[i] = filename[last_slash + i];
	}
	fullname[fullname_length] = '\0';

	return fullname;
}
void path_file_get_fullname__delete(str self)
{
	free(self);
	self = NULL;
}

/*
*	This function returns the base filename (no path included or file extension). Returns: Resource
*	Note: Returns a null pointer if the filename is NULL or empty string.
*	Note: The returned string must be freed by the caller.
*/
str path_file_get_basename__new(str filename)
{
	assert(filename != NULL);
	assert(filename != "");
	if (filename == NULL || filename == "")
		return NULL; // Incorrect filename, returning a null pointer.

	// Find the last slash in the filename
	i64 last_slash = 0;
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '/' || filename[i] == '\\')
			last_slash = i + 1;
	}

	// Search for the last dot in the filename
	i64 last_dot = strlen(filename); // if there is no dot in the filename then use the length of the filename
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '.')
			last_dot = i + 1;
	}

	// Create a string for the base file name to be returned
	i64 basename_length = last_dot - last_slash - 1;
	str basename = (str)malloc(basename_length + 1);

	// If it failed to allocate memory
	if (!basename)
		return NULL;

	// Copy the basename
	for (i64 i = 0; i < basename_length; i++)
	{
		basename[i] = filename[last_slash + i];
	}
	basename[basename_length] = '\0';

	return basename;
}
void path_file_get_basename__delete(str self)
{
	free(self);
	self = NULL;
}

/*
*	This function returns the file extension (no path included). Returns: pack
*	Note: Returns a null pointer if the filename is NULL or empty string.
*	Note: The returned string must be freed by the caller.
*/
str path_file_get_extension__new(str filename)
{
	assert(filename != NULL);
	assert(filename != "");
	if (filename == NULL || filename == "")
		return NULL; // Incorrect filename, returning a null pointer.

	// Search for the last dot in the filename
	i64 last_dot = 0;
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '.')
			last_dot = i + 1;
	}

	// Create a string for the file extension to be returned
	i64 extension_length = strlen(filename) - last_dot;
	str extension = (str)malloc(extension_length + 1);

	// If it failed to allocate memory
	if (!extension)
		return NULL;

	// Copy the extension
	for (i64 i = 0; i < extension_length; i++)
	{
		extension[i] = filename[last_dot + i];
	}
	extension[extension_length] = '\0';

	return extension;
}
void path_file_get_extension__delete(str self)
{
	free(self);
	self = NULL;
}

/*
*	This function returns the file extension with dot (no path included). Returns: .pack
*	Note: Returns a null pointer if the filename is NULL or empty string.
*	Note: The returned string must be freed by the caller.
*/
str path_file_get_extension_dot__new(str filename)
{
	assert(filename != NULL);
	assert(filename != "");
	if (filename == NULL || filename == "")
		return NULL; // Incorrect filename, returning a null pointer.

	// Search for the last dot in the filename
	i64 last_dot = 0;
	for (i64 i = 0; i < (i64)strlen(filename); i++)
	{
		if (filename[i] == '.')
			last_dot = i;
	}

	// Create a string for the file extension to be returned
	i64 extension_length = strlen(filename) - last_dot;
	str extension = (str)malloc(extension_length + 1);

	// If it failed to allocate memory
	if (!extension)
		return NULL;

	// Copy the extension
	for (i64 i = 0; i < extension_length; i++)
	{
		extension[i] = filename[last_dot + i];
	}
	extension[extension_length] = '\0';

	return extension;
}
void path_file_get_extension_dot__delete(str self)
{
	free(self);
	self = NULL;
}