#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H
#include <pinocchio.h>

#define ORGANIZATION_ROOTPACKAGE_SIZE 3
#define ORGANIZATION_ROOTPACKAGE_VARS L"members" 

#define ORGANIZATION_PACKAGE_SIZE ORGANIZATION_ROOTPACKAGE_SIZE + 2
#define ORGANIZATION_PACKAGE_VARS ORGANIZATION_ROOTPACKAGE_VARS, L"parent", L"packageName"

EXPORT_CLASS(Organization_RootPackage);
EXPORT_REFERENCE(Organization_RootPackage);

EXPORT_CLASS(Organization_Package);
EXPORT_REFERENCE(Organization_Package);

extern Object RootPackage;

extern void bootstrap();
extern Object new_Organization_Package(Object parent, Object name);

#endif // BOOTSTRAP_H
