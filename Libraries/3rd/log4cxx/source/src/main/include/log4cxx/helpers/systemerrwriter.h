/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG4CXX_HELPERS_SYSTEMERRWRITER_H
#define _LOG4CXX_HELPERS_SYSTEMERRWRITER_H

#include <log4cxx/helpers/writer.h>

namespace log4cxx
{
namespace helpers
{

/**
*   Sends output to <code>stderr</code>.
*/
class LOG4CXX_EXPORT SystemErrWriter : public Writer
{
	public:
		DECLARE_LOG4CXX_OBJECT(SystemErrWriter)
		BEGIN_LOG4CXX_CAST_MAP()
		LOG4CXX_CAST_ENTRY(SystemErrWriter)
		LOG4CXX_CAST_ENTRY_CHAIN(Writer)
		END_LOG4CXX_CAST_MAP()

		SystemErrWriter();
		virtual ~SystemErrWriter();

		void close(Pool& p) override;
		void flush(Pool& p) override;
		void write(const LogString& str, Pool& p) override;

		static void write(const LogString& str);
		static void flush();

	private:
		SystemErrWriter(const SystemErrWriter&);
		SystemErrWriter& operator=(const SystemErrWriter&);
		static bool isWide();
};

} // namespace helpers

}  //namespace log4cxx

#endif //_LOG4CXX_HELPERS_SYSTEMERRWRITER_H
