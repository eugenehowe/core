#pragma once

#include "LPUpxPapx.h"
#include "LPUpxChpx.h"
#include "LPUpxTapx.h"
#include "Constants.h"

namespace ASCDocFileFormat
{
	//!!!TODO: The revision-marking information and formatting for the style.!!!
	class StkParaGRLPUPX: public IOperand
	{
	private:
		LPUpxPapx lPUpxPapx;
		LPUpxChpx lPUpxChpx;

		byte* bytes;
		unsigned int sizeInBytes;
		unsigned int sizeInBytesWithoutPadding;

	public:

		StkParaGRLPUPX () : lPUpxPapx(), lPUpxChpx(), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
		}

		explicit StkParaGRLPUPX( const LPUpxPapx& _lPUpxPapx, const LPUpxChpx& _lPUpxChpx ) : lPUpxPapx(_lPUpxPapx), lPUpxChpx(_lPUpxChpx), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			this->sizeInBytes = ( _lPUpxPapx.Size() + _lPUpxChpx.Size() );
			this->sizeInBytesWithoutPadding = ( _lPUpxPapx.SizeWithoutPadding() + _lPUpxChpx.SizeWithoutPadding() );

			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, (byte*)_lPUpxPapx, _lPUpxPapx.Size() );
					memcpy( ( this->bytes + _lPUpxPapx.Size() ), (byte*)_lPUpxChpx, _lPUpxChpx.Size() );
				}
			}
		}

		StkParaGRLPUPX( const StkParaGRLPUPX& _stkParaGRLPUPX ) : lPUpxPapx(_stkParaGRLPUPX.lPUpxPapx), lPUpxChpx(_stkParaGRLPUPX.lPUpxChpx), bytes(NULL), sizeInBytes(_stkParaGRLPUPX.sizeInBytes), sizeInBytesWithoutPadding(_stkParaGRLPUPX.sizeInBytesWithoutPadding)
		{
			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, _stkParaGRLPUPX.bytes, this->sizeInBytes );
				}
			}
		}

		virtual ~StkParaGRLPUPX()
		{
			RELEASEARRAYOBJECTS (bytes);
		}

		const vector<Prl> GetProperties() const
		{
			vector<Prl> chpxProperties = this->lPUpxChpx.GetProperties();
			vector<Prl> papxProperties = this->lPUpxPapx.GetProperties();

			vector<Prl> properties;

			for ( vector<Prl>::const_iterator iter = chpxProperties.begin(); iter != chpxProperties.end(); iter++ )
			{
				properties.push_back( *iter );  
			}

			for ( vector<Prl>::const_iterator iter = papxProperties.begin(); iter != papxProperties.end(); iter++ )
			{
				properties.push_back( *iter );  
			}

			return properties;
		}

		virtual operator byte*() const
		{
			return this->bytes;
		}

		virtual operator const byte*() const
		{
			return (const byte*)this->bytes;
		}

		virtual unsigned int Size() const
		{
			return this->sizeInBytes;
		}

		unsigned int SizeWithoutPadding() const
		{
			return this->sizeInBytesWithoutPadding;
		}
	};

	//!!!TODO: The revision-marking information and formatting for the style.!!!
	class StkCharGRLPUPX: public IOperand
	{
	private:
		LPUpxChpx lPUpxChpx;

		byte* bytes;
		unsigned int sizeInBytes;
		unsigned int sizeInBytesWithoutPadding;

	public:

		StkCharGRLPUPX() : lPUpxChpx(), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
		}

		explicit StkCharGRLPUPX( const LPUpxChpx& _lPUpxChpx ) : lPUpxChpx(_lPUpxChpx), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			this->sizeInBytes = _lPUpxChpx.Size();
			this->sizeInBytesWithoutPadding = _lPUpxChpx.SizeWithoutPadding();

			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, (byte*)_lPUpxChpx, _lPUpxChpx.Size() );
				}
			}
		}

		StkCharGRLPUPX( const StkCharGRLPUPX& _stkCharGRLPUPX ) : lPUpxChpx(_stkCharGRLPUPX.lPUpxChpx), bytes(NULL), sizeInBytes(_stkCharGRLPUPX.sizeInBytes), sizeInBytesWithoutPadding(_stkCharGRLPUPX.sizeInBytesWithoutPadding)
		{
			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, _stkCharGRLPUPX.bytes, this->sizeInBytes );
				}
			}
		}

		virtual ~StkCharGRLPUPX()
		{
			RELEASEARRAYOBJECTS (bytes);
		}

		const vector<Prl> GetProperties() const
		{
			return this->lPUpxChpx.GetProperties();
		}

		virtual operator byte*() const
		{
			return this->bytes;
		}

		virtual operator const byte*() const
		{
			return (const byte*)this->bytes;
		}

		virtual unsigned int Size() const
		{
			return this->sizeInBytes;
		}

		unsigned int SizeWithoutPadding() const
		{
			return this->sizeInBytesWithoutPadding;
		}
	};

	class StkTableGRLPUPX: public IOperand
	{
	private:
		LPUpxTapx lPUpxTapx;
		LPUpxPapx lPUpxPapx;
		LPUpxChpx lPUpxChpx;

		byte* bytes;
		unsigned int sizeInBytes;
		unsigned int sizeInBytesWithoutPadding;

	public:
		StkTableGRLPUPX():
		  lPUpxTapx(), lPUpxPapx(), lPUpxChpx(), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		  {
		  }

		  explicit StkTableGRLPUPX( const LPUpxTapx& _lPUpxTapx, const LPUpxPapx& _lPUpxPapx, const LPUpxChpx& _lPUpxChpx ):
		  lPUpxTapx(_lPUpxTapx), lPUpxPapx(_lPUpxPapx), lPUpxChpx(_lPUpxChpx), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		  {
			  this->sizeInBytes = ( _lPUpxTapx.Size() + _lPUpxPapx.Size() + _lPUpxChpx.Size() );
			  this->sizeInBytesWithoutPadding = ( _lPUpxTapx.SizeWithoutPadding() + _lPUpxPapx.SizeWithoutPadding() + _lPUpxChpx.SizeWithoutPadding() );

			  if ( this->sizeInBytes > 0 )
			  {
				  this->bytes = new byte[this->sizeInBytes];

				  if ( this->bytes != NULL )
				  {
					  memset( this->bytes, 0, this->sizeInBytes );

					  memcpy( this->bytes, (byte*)_lPUpxTapx, _lPUpxTapx.Size() );
					  memcpy( ( this->bytes + _lPUpxTapx.Size() ), (byte*)_lPUpxPapx, _lPUpxPapx.Size() );
					  memcpy( ( this->bytes + _lPUpxTapx.Size() + _lPUpxPapx.Size() ), (byte*)_lPUpxChpx, _lPUpxChpx.Size() );
				  }
			  }
		  }

		  StkTableGRLPUPX( const StkTableGRLPUPX& _stkTableGRLPUPX ):
		  lPUpxTapx(_stkTableGRLPUPX.lPUpxTapx), lPUpxPapx(_stkTableGRLPUPX.lPUpxPapx), lPUpxChpx(_stkTableGRLPUPX.lPUpxChpx), bytes(NULL), sizeInBytes(_stkTableGRLPUPX.sizeInBytes), sizeInBytesWithoutPadding(_stkTableGRLPUPX.sizeInBytesWithoutPadding)
		  {
			  if ( this->sizeInBytes > 0 )
			  {
				  this->bytes = new byte[this->sizeInBytes];

				  if ( this->bytes != NULL )
				  {
					  memset( this->bytes, 0, this->sizeInBytes );

					  memcpy( this->bytes, _stkTableGRLPUPX.bytes, this->sizeInBytes );
				  }
			  }
		  }

		  virtual ~StkTableGRLPUPX()
		  {
			  RELEASEARRAYOBJECTS (bytes);
		  }

		  const vector<Prl> GetProperties() const
		  {
			  vector<Prl> chpxProperties = this->lPUpxChpx.GetProperties();
			  vector<Prl> papxProperties = this->lPUpxPapx.GetProperties();
			  vector<Prl> tapxProperties = this->lPUpxTapx.GetProperties();

			  vector<Prl> properties;

			  for ( vector<Prl>::const_iterator iter = chpxProperties.begin(); iter != chpxProperties.end(); iter++ )
			  {
				  properties.push_back( *iter );  
			  }

			  for ( vector<Prl>::const_iterator iter = papxProperties.begin(); iter != papxProperties.end(); iter++ )
			  {
				  properties.push_back( *iter );  
			  }

			  for ( vector<Prl>::const_iterator iter = tapxProperties.begin(); iter != tapxProperties.end(); iter++ )
			  {
				  properties.push_back( *iter );  
			  }

			  return properties;
		  }

		  virtual operator byte*() const
		  {
			  return this->bytes;
		  }

		  virtual operator const byte*() const
		  {
			  return (const byte*)this->bytes;
		  }

		  virtual unsigned int Size() const
		  {
			  return this->sizeInBytes;
		  }

		  unsigned int SizeWithoutPadding() const
		  {
			  return this->sizeInBytesWithoutPadding;
		  }
	};

	class StkListGRLPUPX: public IOperand
	{
	private:
		LPUpxPapx lPUpxPapx;

		byte* bytes;
		unsigned int sizeInBytes;
		unsigned int sizeInBytesWithoutPadding;

	public:
		StkListGRLPUPX():
		  lPUpxPapx(), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		  {
		  }

		  explicit StkListGRLPUPX( const LPUpxPapx& _lPUpxPapx ):
		  lPUpxPapx(_lPUpxPapx), bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		  {
			  this->sizeInBytes = _lPUpxPapx.Size();
			  this->sizeInBytesWithoutPadding = _lPUpxPapx.SizeWithoutPadding();

			  if ( this->sizeInBytes > 0 )
			  {
				  this->bytes = new byte[this->sizeInBytes];

				  if ( this->bytes != NULL )
				  {
					  memset( this->bytes, 0, this->sizeInBytes );

					  memcpy( this->bytes, (byte*)_lPUpxPapx, _lPUpxPapx.Size() );
				  }
			  }
		  }

		  StkListGRLPUPX( const StkListGRLPUPX& _stkListGRLPUPX ):
		  lPUpxPapx(_stkListGRLPUPX.lPUpxPapx), bytes(NULL), sizeInBytes(_stkListGRLPUPX.sizeInBytes), sizeInBytesWithoutPadding(_stkListGRLPUPX.sizeInBytesWithoutPadding)
		  {
			  if ( this->sizeInBytes > 0 )
			  {
				  this->bytes = new byte[this->sizeInBytes];

				  if ( this->bytes != NULL )
				  {
					  memset( this->bytes, 0, this->sizeInBytes );

					  memcpy( this->bytes, _stkListGRLPUPX.bytes, this->sizeInBytes );
				  }
			  }
		  }

		  virtual ~StkListGRLPUPX()
		  {
			  RELEASEARRAYOBJECTS (bytes);
		  }

		  const vector<Prl> GetProperties() const
		  {
			  return this->lPUpxPapx.GetProperties();
		  }

		  virtual operator byte*() const
		  {
			  return this->bytes;
		  }

		  virtual operator const byte*() const
		  {
			  return (const byte*)this->bytes;
		  }

		  virtual unsigned int Size() const
		  {
			  return this->sizeInBytes;
		  }

		  unsigned int SizeWithoutPadding() const
		  {
			  return this->sizeInBytesWithoutPadding;
		  }
	};

	class GrLPUpxSw: public IOperand
	{
	public:
		GrLPUpxSw() :  bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
		}

		explicit GrLPUpxSw( const StkParaGRLPUPX& _stkParaGRLPUPX ) : bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			this->sizeInBytes = _stkParaGRLPUPX.Size();
			this->sizeInBytesWithoutPadding = _stkParaGRLPUPX.SizeWithoutPadding();
			this->properties = _stkParaGRLPUPX.GetProperties();

			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, (byte*)_stkParaGRLPUPX, _stkParaGRLPUPX.Size() );
				}
			}
		}

		explicit GrLPUpxSw( const StkCharGRLPUPX& _stkCharGRLPUPX ) : bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			this->sizeInBytes = _stkCharGRLPUPX.Size();
			this->sizeInBytesWithoutPadding = _stkCharGRLPUPX.SizeWithoutPadding();
			this->properties = _stkCharGRLPUPX.GetProperties();

			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, (byte*)_stkCharGRLPUPX, _stkCharGRLPUPX.Size() );
				}
			}
		}

		explicit GrLPUpxSw( const StkTableGRLPUPX& _stkTableGRLPUPX ) : bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			this->sizeInBytes = _stkTableGRLPUPX.Size();
			this->sizeInBytesWithoutPadding = _stkTableGRLPUPX.SizeWithoutPadding();
			this->properties = _stkTableGRLPUPX.GetProperties();

			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, (byte*)_stkTableGRLPUPX, _stkTableGRLPUPX.Size() );
				}
			}
		}

		explicit GrLPUpxSw( const StkListGRLPUPX& _stkListGRLPUPX ) : bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			this->sizeInBytes = _stkListGRLPUPX.Size();
			this->sizeInBytesWithoutPadding = _stkListGRLPUPX.SizeWithoutPadding();
			this->properties = _stkListGRLPUPX.GetProperties();

			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, (byte*)_stkListGRLPUPX, _stkListGRLPUPX.Size() );
				}
			}
		}

		explicit GrLPUpxSw( const Constants::StyleType _styleType, const ASCDocFileFormat::LPUpxPapx& _lPUpxPapx, const ASCDocFileFormat::LPUpxChpx& _lPUpxChpx, const ASCDocFileFormat::LPUpxTapx& _lPUpxTapx ) : bytes(NULL), sizeInBytes(0), sizeInBytesWithoutPadding(0)
		{
			switch ( _styleType )
			{
			case Constants::styleTypeParagraph:
				{
					*this = GrLPUpxSw( ASCDocFileFormat::StkParaGRLPUPX( _lPUpxPapx, _lPUpxChpx ) );
				}
				break;

			case Constants::styleTypeCharacter:
				{
					*this = GrLPUpxSw( ASCDocFileFormat::StkCharGRLPUPX( _lPUpxChpx ) );
				}
				break;

			case Constants::styleTypeTable:
				{
					*this = GrLPUpxSw( ASCDocFileFormat::StkTableGRLPUPX( _lPUpxTapx, _lPUpxPapx, _lPUpxChpx ) );
				}
				break;

			case Constants::styleTypeNumbering:
				{
					*this = GrLPUpxSw( ASCDocFileFormat::StkListGRLPUPX( _lPUpxPapx ) );
				}
				break;
			}
		}

		GrLPUpxSw( const GrLPUpxSw& _grLPUpxSw ) : properties(_grLPUpxSw.properties), bytes(NULL), sizeInBytes(_grLPUpxSw.sizeInBytes), sizeInBytesWithoutPadding(_grLPUpxSw.sizeInBytesWithoutPadding)
		{
			if ( this->sizeInBytes > 0 )
			{
				this->bytes = new byte[this->sizeInBytes];

				if ( this->bytes != NULL )
				{
					memset( this->bytes, 0, this->sizeInBytes );

					memcpy( this->bytes, _grLPUpxSw.bytes, this->sizeInBytes );
				}
			}
		}

		bool operator == ( const GrLPUpxSw& _grLPUpxSw )
		{
			return ( ( this->sizeInBytes == _grLPUpxSw.sizeInBytes ) && 
				( this->sizeInBytesWithoutPadding == _grLPUpxSw.sizeInBytesWithoutPadding ) &&
				( memcmp( this->bytes, _grLPUpxSw.bytes, this->sizeInBytes ) == 0 ) );
		}

		bool operator != ( const GrLPUpxSw& _grLPUpxSw )
		{
			return !( this->operator == ( _grLPUpxSw ) );
		}

		GrLPUpxSw& operator = ( const GrLPUpxSw& _grLPUpxSw )
		{
			if ( *this != _grLPUpxSw )
			{
				RELEASEARRAYOBJECTS (bytes);

				this->sizeInBytes = _grLPUpxSw.sizeInBytes;
				this->sizeInBytesWithoutPadding = _grLPUpxSw.sizeInBytesWithoutPadding;
				this->properties = _grLPUpxSw.properties;

				if ( this->sizeInBytes > 0 )
				{
					this->bytes = new byte[this->sizeInBytes];

					if ( this->bytes != NULL )
					{
						memset( this->bytes, 0, this->sizeInBytes );

						memcpy( this->bytes, _grLPUpxSw.bytes, this->sizeInBytes );
					}
				}
			}

			return *this;
		}

		virtual ~GrLPUpxSw()
		{
			RELEASEARRAYOBJECTS (bytes);
		}

		const vector<Prl> GetProperties() const
		{
			return this->properties;
		}

		virtual operator byte*() const
		{
			return this->bytes;
		}

		virtual operator const byte*() const
		{
			return (const byte*)this->bytes;
		}

		virtual unsigned int Size() const
		{
			return this->sizeInBytes;
		}

		unsigned int SizeWithoutPadding() const
		{
			return this->sizeInBytesWithoutPadding;
		}
	private:

		vector<Prl> properties;

		byte* bytes;
		unsigned int sizeInBytes;
		unsigned int sizeInBytesWithoutPadding;
	};
}