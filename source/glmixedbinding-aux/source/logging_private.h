#pragma once


namespace glmixedbinding { namespace aux
{


void startWriter(const std::string & filepath);
const std::string getStandardFilepath();

using LogEntry = FunctionCall *;
using TailIdentifier = unsigned int;
TailIdentifier addTail();
void removeTail(TailIdentifier);
const std::vector<LogEntry>::const_iterator cbegin(TailIdentifier key);
bool valid(TailIdentifier key, const std::vector<LogEntry>::const_iterator & it);
const std::vector<LogEntry>::const_iterator next(TailIdentifier key, const std::vector<LogEntry>::const_iterator & it);
unsigned int size(TailIdentifier key);


} } // namespace glmixedbinding::aux
