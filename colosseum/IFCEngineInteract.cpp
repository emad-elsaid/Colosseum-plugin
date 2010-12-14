#include "stdafx.h"
#include "IFCEngineInteract.h"
#include "colosseumCtrl.h"

int		g_model = 0, g_noVertices, g_noIndices, * g_pIndices;
float	* g_pVertices;
char	* g_ifcSchemaName = NULL;


CIFCEngineInteract::CIFCEngineInteract()
{
	m_firstInstance = NULL;
	m_lastInstance = NULL;
}

void CIFCEngineInteract::initIFCEngineInteract()
{

	m_firstInstance = NULL;
	m_lastInstance = NULL;
}

STRUCT_INSTANCES * CIFCEngineInteract::addObject(STRUCT_INSTANCES * parent, int id, char * name)
{
	if	(m_lastInstance) {
		m_lastInstance->next = new(STRUCT_INSTANCES);
		m_lastInstance = m_lastInstance->next;
	} else {
		m_firstInstance = new(STRUCT_INSTANCES);
		m_lastInstance = m_firstInstance;
	}

	if	( (name)  &&
		  (name[0]) ) {
		m_lastInstance->name = name;
	} else {
		m_lastInstance->name = _T("<no text available>");
	}
	m_lastInstance->parent = parent;
	m_lastInstance->next = NULL;
	m_lastInstance->select = ITEM_CHECKED;
	m_lastInstance->id = id;

	return	m_lastInstance;
}

void  CIFCEngineInteract::retrieveObjects(char * ObjectSPFFName, char * ObjectGroupName)
{
	STRUCT_INSTANCES	* parent;
	int					i, object, * objects, noObjects;
	char				* string;

	objects = sdaiGetEntityExtentBN(g_model, ObjectSPFFName);
	noObjects = sdaiGetMemberCount(objects);
	if	(noObjects) {
		parent = addObject(NULL, 0, ObjectGroupName);

		for (i = 0; i < noObjects; ++i) {
			engiGetAggrElement(objects, i, sdaiINSTANCE, &object);

			//
			//	The loaded schema in openSPFFFile is needed to interpret 'GlobalId' in this function
			//
			sdaiGetAttrBN(object, "GlobalId", sdaiSTRING, &string);

			addObject(parent, object, string);
		}
	}
}

int	 CIFCEngineInteract::retrieveObjectGroups(char * fileName)
{
	if  (g_model) {
		sdaiCloseModel(g_model);
        g_model = 0;
    }

	g_model = sdaiOpenModelBN(0, fileName, g_ifcSchemaName);

	if	(g_model) {
		retrieveObjects(_T("IFCANNOTATION"), _T("Annotations"));
		retrieveObjects(_T("IFCBEAM"), _T("Beams"));
		retrieveObjects(_T("IFCBUILDING"), _T("Buildings"));
        retrieveObjects(_T("IFCBUILDINGELEMENTPART"), _T("Building Element Parts"));		
        retrieveObjects(_T("IFCBUILDINGELEMENTPROXY"), _T("Building Element Proxies"));		
		retrieveObjects(_T("IFCBUILDINGSTOREY"), _T("Building Stories"));
		retrieveObjects(_T("IFCCHAMFEREDGEFEATURE"), _T("Chamfer Edge Features"));
		retrieveObjects(_T("IFCCOLUMN"), _T("Columns"));		
		retrieveObjects(_T("IFCCOVERING"), _T("Coverings"));		
		retrieveObjects(_T("IFCCURTAINWALL"), _T("Curtain Walls"));
		retrieveObjects(_T("IFCDISCRETEACCESSORY"), _T("Discrete Accessories"));		
		retrieveObjects(_T("IFCDISTRIBUTIONCHAMBERELEMENT"), _T("Distribution Chamber Elements"));
		retrieveObjects(_T("IFCDISTRIBUTIONCONTROLELEMENT"), _T("Distribution Control Elements"));
		retrieveObjects(_T("IFCDISTRIBUTIONELEMENT"), _T("Distribution Elements"));
		retrieveObjects(_T("IFCDISTRIBUTIONFLOWELEMENT"), _T("Distribution Flow Elements"));
		retrieveObjects(_T("IFCDISTRIBUTIONPORT"), _T("Distribution Ports"));
		retrieveObjects(_T("IFCDOOR"), _T("Doors"));		
		retrieveObjects(_T("IFCELECTRICALELEMENT"), _T("Electrical Elements"));		
		retrieveObjects(_T("IFCELECTRICDISTRIBUTIONPOINT"), _T("Electric Distribution Points"));		
		retrieveObjects(_T("IFCELEMENTASSEMBLY"), _T("Element Assemblies"));		
		retrieveObjects(_T("IFCENERGYCONVERSIONDEVICE"), _T("Energy Conversion Devices"));	
		retrieveObjects(_T("IFCEQUIPMENTELEMENT"), _T("Equipment Elements"));	
		retrieveObjects(_T("IFCFASTENER"), _T("Fasteners"));		
		retrieveObjects(_T("IFCFLOWCONTROLLER"), _T("Flow Controllers"));		
		retrieveObjects(_T("IFCFLOWFITTING"), _T("Flow Fittings"));		
		retrieveObjects(_T("IFCFLOWMOVINGDEVICE"), _T("Flow Moving Devices"));		
		retrieveObjects(_T("IFCFLOWSEGMENT"), _T("Flow Segments"));		
		retrieveObjects(_T("IFCFLOWSTORAGEDEVICE"), _T("Flow Storage Devices"));		
		retrieveObjects(_T("IFCFLOWTERMINAL"), _T("Flow Terminals"));		
		retrieveObjects(_T("IFCFLOWTREATMENTDEVICE"), _T("Flow Treatment Devices"));		
		retrieveObjects(_T("IFCFOOTING"), _T("Footings"));		
		retrieveObjects(_T("IFCFURNISHINGELEMENT"), _T("Furnishing Elements"));		
		retrieveObjects(_T("IFCGRID"), _T("Grids"));
		retrieveObjects(_T("IFCMECHANICALFASTENER"), _T("Mechanical Fasteners"));		
		retrieveObjects(_T("IFCMEMBER"), _T("Members"));		
		//retrieveObjects(_T("IFCOPENINGELEMENT"), _T("Opening Elements"));		
		retrieveObjects(_T("IFCPILE"), _T("Piles"));		
		retrieveObjects(_T("IFCPLATE"), _T("Plates"));		
		retrieveObjects(_T("IFCPROJECTIONELEMENT"), _T("Projection Elements"));		
		retrieveObjects(_T("IFCPROXY"), _T("Proxies"));
		retrieveObjects(_T("IFCRAILING"), _T("Railings"));		
		retrieveObjects(_T("IFCRAMP"), _T("Ramps"));		
		retrieveObjects(_T("IFCRAMPFLIGHT"), _T("Ramp Flights"));		
		retrieveObjects(_T("IFCREINFORCINGBAR"), _T("Reinforcing Bars"));		
		retrieveObjects(_T("IFCREINFORCINGMESH"), _T("Reinforcing Meshes"));		
		retrieveObjects(_T("IFCROOF"), _T("Roofs"));		
		retrieveObjects(_T("IFCROUNDEDEDGEFEATURE"), _T("Rounded Edge Features"));		
		retrieveObjects(_T("IFCSITE"), _T("Sites"));		
		retrieveObjects(_T("IFCSLAB"), _T("Slabs"));		
		//retrieveObjects(_T("IFCSPACE"), _T("Spaces"));		
		retrieveObjects(_T("IFCSTAIR"), _T("Stairs"));		
		retrieveObjects(_T("IFCSTAIRFLIGHT"), _T("Stair Flights"));		
		retrieveObjects(_T("IFCSTRUCTURALCURVECONNECTION"), _T("Structural Curve Connections"));		
		retrieveObjects(_T("IFCSTRUCTURALCURVEMEMBER"), _T("Structural Curve Members"));		
		retrieveObjects(_T("IFCSTRUCTURALCURVEMEMBERVARYING"), _T("Structural Curve Member Varyings"));		
		retrieveObjects(_T("IFCSTRUCTURALLINEARACTION"), _T("Structural Linear Actions"));		
		retrieveObjects(_T("IFCSTRUCTURALLINEARACTIONVARYING"), _T("Structural Linear Action Varyings"));		
		retrieveObjects(_T("IFCSTRUCTURALPLANARACTION"), _T("Structural Planar Actions"));		
		retrieveObjects(_T("IFCSTRUCTURALPLANARACTIONVARYING"), _T("Structural Planar Action Varyings"));		
		retrieveObjects(_T("IFCSTRUCTURALPOINTACTION"), _T("Structural Point Actions"));		
		retrieveObjects(_T("IFCSTRUCTURALPOINTCONNECTION"), _T("Structural Point Connections"));		
		retrieveObjects(_T("IFCSTRUCTURALPOINTREACTION"), _T("Structural Point Reactions"));		
		retrieveObjects(_T("IFCSTRUCTURALSURFACECONNECTION"), _T("Structural Surface Connections"));		
		retrieveObjects(_T("IFCSTRUCTURALSURFACEMEMBER"), _T("Structural Surface Members"));		
		retrieveObjects(_T("IFCSTRUCTURALSURFACEMEMBERVARYING"), _T("Structural Surface Member Varyings"));		
		retrieveObjects(_T("IFCTENDON"), _T("Tendons"));		
		retrieveObjects(_T("IFCTENDONANCHOR"), _T("Tendon Anchors"));		
		retrieveObjects(_T("IFCTRANSPORTELEMENT"), _T("Transport Elements"));		
		retrieveObjects(_T("IFCVIRTUALELEMENT"), _T("Virtual Elements"));		
		retrieveObjects(_T("IFCWALL"), _T("Walls"));		
		retrieveObjects(_T("IFCWALLSTANDARDCASE"), _T("Walls Standard Cases"));		
		retrieveObjects(_T("IFCWINDOW"), _T("Windows"));
	} else {
		return	-1;
	}

	return	0;
}

void  CIFCEngineInteract::enrichObjectGroups()
{
	STRUCT_INSTANCES	* instance;

	if	(m_firstInstance) {
		//
		//	We need to build up the 3D structure in the IFC Engine DLL to retrieve geometrical data
		//
		initializeModelling(g_model, &g_noVertices, &g_noIndices, 1);
		g_pVertices = (float *) malloc(g_noVertices * sizeof(CUSTOMVERTEX));
		g_pIndices = (int *) malloc(g_noIndices * sizeof(int));
		finalizeModelling(g_model, &g_pVertices[0], &g_pIndices[0], D3DFVF_CUSTOMVERTEX);

		instance = m_firstInstance;

		while  (instance) {
			if	(instance->parent) {
				getInstanceInModelling(g_model, instance->id, 1, &instance->startVertex, &instance->startIndex, &instance->primitiveCount);
			}

			instance = instance->next;
		}
	}
}

STRUCT_INSTANCES  *CIFCEngineInteract::getFirstInstance() const
{
	return m_firstInstance;
}

CIFCEngineInteract::~CIFCEngineInteract()
{
	TRACE("Delete CIFCEngineInteract");
}