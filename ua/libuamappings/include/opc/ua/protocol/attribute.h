/// @author Alexander Rykovanov 2012
/// @email rykovanov.as@gmail.com
/// @brief Opc Ua Binary. Attributes service.
/// @license GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at 
/// http://www.gnu.org/licenses/lgpl.html)
///

#ifndef __OPC_UA_BINARY_ATTRIBUTES_H__
#define __OPC_UA_BINARY_ATTRIBUTES_H__

#include <opc/ua/attribute_ids.h>
#include <opc/ua/protocol/data_value.h>
#include <opc/ua/protocol/types.h>
#include <opc/ua/protocol/variant.h>

namespace OpcUa
{

  struct AttributeValueID
  {
    NodeID Node;
    AttributeID Attribute;
    std::string IndexRange;
    QualifiedName DataEncoding;

    AttributeValueID();
  };

  struct ReadParameters
  {
    Duration MaxAge;
    TimestampsToReturn TimestampsType;
    std::vector<AttributeValueID> AttributesToRead;

    ReadParameters();
  };

  struct ReadRequest
  {
    NodeID TypeID;
    RequestHeader Header;
    ReadParameters Parameters;

    ReadRequest();
  };

  struct ReadResult
  {
    std::vector<DataValue> Results;
    std::vector<DiagnosticInfo> Diagnostics;
  };


  struct ReadResponse
  {
    NodeID TypeID;
    ResponseHeader Header;
    ReadResult Result;

    ReadResponse();
  };


  struct WriteValue
  {
    NodeID Node;
    AttributeID Attribute;
    std::string NumericRange;
    DataValue Data;
  };

  struct WriteRequest
  {
    NodeID TypeID;
    RequestHeader Header;

    std::vector<WriteValue> NodesToWrite;

    WriteRequest();
  };

  struct WriteResponse
  {
    NodeID TypeID;
    ResponseHeader Header;

    std::vector<StatusCode> StatusCodes;
    std::vector<DiagnosticInfo> Diagnostics;

    WriteResponse();
  };

} // namespace OpcUa

#endif // __OPC_UA_BINARY_ATTRIBUTES_H__
