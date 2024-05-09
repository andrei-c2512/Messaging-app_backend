#include <QByteArray>
#include <qDebug>
#include <QTcpSocket>

struct MediaData {
	MediaData(QByteArray blob, qsizetype id, int extension);
	MediaData(qsizetype id, int extension);
	QByteArray blob;
	qsizetype id;
	int extension;
};
class MediaHandler {
public:
	MediaHandler();
	bool mediaReady() const;
	//the last byte of the chunk should represent if it is the final chunk or not
	void addChunk(QTcpSocket& socket , qsizetype id , QByteArray& chunk );
	qsizetype makeNewSlot( int extension );
	std::unique_ptr<MediaData> readyMedia();
private:
	qsizetype sequence;
	std::vector<MediaData> mediaList;
	
	std::unique_ptr<MediaData> _readyMedia;
	bool _mediaReady;
};