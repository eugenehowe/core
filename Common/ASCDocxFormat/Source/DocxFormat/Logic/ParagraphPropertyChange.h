#pragma once
#ifndef OOX_LOGIC_PARAGRAPH_PROPERTY_CHANGE_INCLUDE_H_
#define OOX_LOGIC_PARAGRAPH_PROPERTY_CHANGE_INCLUDE_H_

#include "./../WritingElement.h"
#include <string>
#include "nullable_property.h"

namespace OOX
{
	namespace Logic
	{
		class ParagraphPropertyChange : public WritingElement
		{
		public:
			ParagraphPropertyChange();
			virtual ~ParagraphPropertyChange();
			explicit ParagraphPropertyChange(const XML::XNode& node);
			const ParagraphPropertyChange& operator =(const XML::XNode& node);

		public:
			virtual void fromXML(const XML::XNode& node);
			virtual const XML::XNode toXML() const;
		
		public:
            nullable_property<int>         Id;
			nullable_property<std::string> Author;
			nullable_property<std::string> Date;
			
		};
	} // namespace Logic
} // namespace OOX

#endif // OOX_LOGIC_PARAGRAPH_PROPERTY_CHANGE_INCLUDE_H_