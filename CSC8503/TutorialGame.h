#include "../NCLCoreClasses/KeyboardMouseController.h"

#pragma once
#include "GameTechRenderer.h"
#ifdef USEVULKAN
#include "GameTechVulkanRenderer.h"
#endif
#include "PhysicsSystem.h"

#include "StateGameObject.h"

namespace NCL {
	namespace CSC8503 {
		class TutorialGame		{
		public:
			TutorialGame();
			~TutorialGame();

			virtual void UpdateGame(float dt);

		protected:
			void InitialiseAssets();

			void InitCamera();
			void UpdateKeys();

			void InitWorld();

			void BridgeConstraintTest();

			//void InitMazeWorld();

			/*
			These are some of the world/object creation functions I created when testing the functionality
			in the module. Feel free to mess around with them to see different objects being created in different
			test scenarios (constraints, collision types, and so on). 
			*/
			void InitGameExamples();

			void InitSphereGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, float radius);
			void InitMixedGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing);
			void InitCubeGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, const Vector3& cubeDims);

			void InitDefaultFloor();

			bool SelectObject();
			void MoveSelectedObject();
			void DebugObjectMovement();
			void LockedObjectMovement();

			void InitGameToolsObject();

			GameObject* AddFloorToWorld(const Vector3& position);
			GameObject* AddCoinToWorldWithColor(const Vector3& position, float radius, float inverseMass = 10.0f,
				std::string name = "uname", Vector4 color = Vector4(1, 1, 1, 1));
			GameObject* AddSphereToWorld(const Vector3& position, float radius, float inverseMass = 10.0f);
			GameObject* AddCubeToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 10.0f);

			GameObject* AddPlayerToWorld(const Vector3& position);
			GameObject* AddEnemyToWorld(const Vector3& position);
			GameObject* AddBonusToWorld(const Vector3& position, Vector4 color);
			GameObject* AddCubePlayerToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 10.0f);

			StateGameObject* AddStateObjectToWorld(const Vector3& position);
			StateGameObject* testStateObject = nullptr;

			StateGameObject* AddStateObjectCubeToWorld(const Vector3& position);
			StateGameObject* testStateCubeObject = nullptr;

#ifdef USEVULKAN
			GameTechVulkanRenderer*	renderer;
#else
			GameTechRenderer* renderer;
#endif
			PhysicsSystem*		physics;
			GameWorld*			world;

			KeyboardMouseController controller;

			bool useGravity;
			bool inSelectionMode;

			float		forceMagnitude;

			GameObject* selectionObject = nullptr;

			Mesh*	capsuleMesh = nullptr;
			Mesh*	cubeMesh	= nullptr;
			Mesh*	sphereMesh	= nullptr;
			Mesh*   coinMesh    = nullptr;

			Texture*	basicTex	= nullptr;
			Texture*    MadokaTex   = nullptr;
			Shader*		basicShader = nullptr;

			//Coursework Meshes
			Mesh*	catMesh		= nullptr;
			Mesh*	kittenMesh	= nullptr;
			Mesh*	enemyMesh	= nullptr;
			Mesh*	bonusMesh	= nullptr;
			Mesh*   charMesh    = nullptr;
			Mesh*   cylinderMesh= nullptr;
			Mesh*   gooseMesh   = nullptr;

			//Coursework Additional functionality	
			GameObject* lockedObject	= nullptr;
			Vector3 lockedOffset		= Vector3(10, 30, 50);
			void LockCameraToObject(GameObject* o) {
				lockedObject = o;
			}

			GameObject* objClosest = nullptr;

			//NavigationGrid *grid = nullptr;

			Camera* cameraMain;
			//GamePlayerFollowCamera* cameraFollow;
			Vector3 startCameraPos = Vector3(512.0f, 40.0f, 512.0f);
		};
	}
}

