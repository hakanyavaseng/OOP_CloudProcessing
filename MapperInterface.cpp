#include "MapperInterface.h"

/**
 * @brief PointCloudGenerator nesnesi ekler
 *
 */
void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
	// generator nesnesini generators vector'üne ekler
	this->generators.push_back(generator);
}

/**
 * @brief PointCloudRecorder nesnesi ayarlar
 *
 * 
 * 
 */


void MapperInterface::setRecorder(PointCloudRecorder* recorder)
{
		// recorder özelliğini belirtilen nesneye atar
		this->recorder = recorder;

}
	/**
	 * @brief nokta bulutunu oluşturur
	 *
	 * @return true
	 */

bool MapperInterface::generate()
{
	PointCloud pc;						// boş bir nokta bulutu oluşturur
	int size = this->generators.size(); // generators vector'ündeki nokta bulutu oluşturucuların sayısını alır

	// generators vector'ündeki tüm nokta bulutu oluşturucuları için döngü oluşturur
	for (int i = 0; i < size; i++)
	{
		pc = pc + generators.at(i)->captureFor();
		// captureFor() işlevi bir nokta bulutu döndürür ve bu nokta bulutunu pc nokta bulutuna ekler
	}
	// Oluşturulan nokta bulutunu pointCloud özelliğine atar
	this->pointCloud = pc;
	return true;
}
/**
 * @brief Nokta bulutunu kaydeder
 *
 * @return true
 */
bool MapperInterface::recordPointCloud()
{
	// recorder özelliğini kullanarak pointCloud özelliğini kaydeder
	this->recorder->save(this->pointCloud);
	return true;
}
/**
 * @brief haritaya kaydeder
 *
 * @return true
 */
bool MapperInterface::recordMap()
{
	// map özelliğini kullanarak haritayı kaydeder ve kaydedilen dosyanın adını getFileName() işlevi ile alır		
	this->map->saveMap(this->recorder->getFileName());
	return true;
}
/**
 * @brief haritayı yükler
 *
 * @return true
 */
bool MapperInterface::insertMap()
{
	// map özelliğini kullanarak haritayı yükler ve yüklenen dosyanın adını getFileName() işlevi ile alır
	this->map->loadMap(this->recorder->getFileName());
	return true;
}
