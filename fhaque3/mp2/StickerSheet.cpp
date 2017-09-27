#include "StickerSheet.h"
using namespace cs225;
StickerSheet::StickerSheet(const Image & picture,unsigned max) {
//imageloc=picture;
max_=max;
}
StickerSheet::~StickerSheet 	( 		) {}	
StickerSheet::StickerSheet 	( 	const StickerSheet &  	other	) 	{}
const StickerSheet& StickerSheet::operator= 	( 	const StickerSheet &  	other	) 	{}
void StickerSheet::changeMaxStickers 	( 	unsigned  	max	){}
int StickerSheet::addSticker 	( 	Image &  	sticker,
		unsigned  	x,
		unsigned  	y 
	) 		{}
bool StickerSheet::translate 	( 	unsigned  	index,
		unsigned  	x,
		unsigned  	y 
	) 	{}
void StickerSheet::removeSticker 	( 	unsigned  	index	) 	{}
Image* StickerSheet::getSticker 	( 	unsigned  	index	) 	const {}

Image StickerSheet::render 	( 		) 	const{}

