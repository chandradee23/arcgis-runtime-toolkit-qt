// Copyright 2016 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <QObject>

#include "ToolkitCommon.h"

namespace Esri
{
namespace ArcGISRuntime
{

class Basemap;
class GeoView;
class Map;
class LayerListModel;
class Scene;

namespace Toolkit
{

class TOOLKIT_EXPORT ObjectPool : public QObject
{
  Q_OBJECT

public:
  explicit ObjectPool(QObject* parent = nullptr);
  ~ObjectPool();

  Scene* map() const;
  void registerMap(Scene* newMap);

  Scene* scene() const;
  void registerScene(Scene* newScene);

  GeoView* geoView() const;
  void registerGeoView(GeoView* newGeoView);

  LayerListModel* operationalLayers() const;

  void setBasemap(Basemap* newBasemap);

  void clear();

signals:
  void sceneChanged();
  void geoViewChanged();
  void mapChanged();

private:
  GeoView* m_geoView = nullptr;
  Scene* m_map = nullptr;
  Scene* m_scene = nullptr;
};

} // Toolkit
} // ArcGISRuntime
} // Esri

#endif // OBJECT_POOL_H
