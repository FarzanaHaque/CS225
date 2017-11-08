/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
//from tileImage vectors create a Point<3> vector
vector<Point<3>> points;

/*auto tsize = theTiles.size() ; // size before the inserts

    // insert 99 at every alternate position (insert 99 n times)
    for( auto iter = std::begin(vec) ; n-- ; ++iter )
        iter = vec.insert( iter+1, 99 ) ; // vec.insert() returns a valid iterator
                                          // to the element that was inserted

    for( int v : vec ) std::cout << v << ' ' ;
    std::cout << '\n' ;
}*/
size_t size=theTiles.size();
//points.reserve(size);

map<Point<3>, int> tmap;






for(size_t a=0;a<size;a++)
{
HSLAPixel avg=theTiles[a].getAverageColor();
/*double temp[3];
temp[0]=avg.h;
temp[1]=avg.s;
temp[2]=avg.l;*/
Point<3>apoint(avg.h/360,avg.s,avg.l);
points.push_back(apoint);
tmap[points[a]] = a;
}




KDTree<3>tree(points);






int rows=theSource.getRows();
int cols=theSource.getColumns();
MosaicCanvas * m=new MosaicCanvas(theSource.getRows(),theSource.getColumns());
for(int i=0;i<rows;i++)
	{
	for(int j=0;j<cols;j++)
		{
		HSLAPixel regcolor=theSource.getRegionColor(i,j);
		Point<3> spoint;
		spoint[0]=regcolor.h/360;
		spoint[1]=regcolor.s;
		spoint[2]=regcolor.l;
		Point<3> nearest=tree.findNearestNeighbor(spoint);
		//found the nearest point, how to find the image again??????
		//m.setTile(i,j,timg); 
		int index=tmap[nearest];
		m->setTile(i,j,theTiles[index]);
		}
	}

return m;
}
/*
For every region in the SourceImage, mapTiles() should take the TileImage with average color closest to the average color of that region and place that TileImage into the MosaicCanvas in the same tile position as the SourceImage’s region.

map_tiles - The locations of the tiles in the mosaic are defined by a MosaicCanvas. This function should create a new MosaicCanvas which is appropriately sized based on the rows and columns of tiles in the SourceImage. Then, each tile in the MosaicCanvas should be set to an appropriate TileImage, using a KDTree to find the Nearest Neighbor for each region.




There are two classes representing a color in this portion of the MP: HSLAPixel and Point<3>. You will need to convert between these different representations.

    Note that your points should be in H-S-L order and hue must be normalized to [0, 1]. That is, hue/360 should be the x

(0th dimension), saturation should be the y (1st dimension), and luminance should be the z

    (2nd dimension).

Use your KDTree class to find the nearest neighbor, which is the tile image that minimizes average color distances.
You can easily convert from a TileImage to its average color using TileImage::getAverageColor(). You will also need to convert from an average color to the TileImage that would generate that color. You may want to use the std::map class to do this.
*/
