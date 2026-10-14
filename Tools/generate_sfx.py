import bpy
import os

# Blender script to generate low-poly Clash Royale-style unit meshes.
# Usage:
#   blender --background --python Tools/blender_generate_lowpoly_units.py

OUT_DIR = os.path.join(os.getcwd(), "GeneratedAssets")
os.makedirs(OUT_DIR, exist_ok=True)


def clear_scene():
    bpy.ops.object.select_all(action='SELECT')
    bpy.ops.object.delete(use_global=False)


def make_material(name, color):
    mat = bpy.data.materials.new(name=name)
    mat.use_nodes = False
    mat.diffuse_color = (*color, 1.0)
    return mat


def add_cube(name, scale, material):
    bpy.ops.mesh.primitive_cube_add(location=(0, 0, 0), scale=(1, 1, 1))
    obj = bpy.context.active_object
    obj.name = name
    obj.scale = scale
    if obj.data.materials:
        obj.data.materials[0] = material
    else:
        obj.data.materials.append(material)
    return obj


def add_uv_sphere(name, radius, material):
    bpy.ops.mesh.primitive_uv_sphere_add(segments=16, ring_count=8, radius=radius)
    obj = bpy.context.active_object
    obj.name = name
    if obj.data.materials:
        obj.data.materials[0] = material
    else:
        obj.data.materials.append(material)
    return obj


def export_obj(obj, filepath):
    obj.select_set(True)
    bpy.context.view_layer.objects.active = obj
    bpy.ops.export_scene.gltf(filepath=filepath, export_format='GLB', use_selection=True)


def generate_units():
    clear_scene()
    blue = make_material("BlueTeam", (0.18, 0.42, 0.95))
    red = make_material("RedTeam", (0.92, 0.22, 0.22))
    neutral = make_material("Neutral", (0.77, 0.72, 0.6))

    tank = add_cube("TankUnit", (0.7, 0.95, 0.7), red)
    tank.rotation_euler[0] = 0.0
    export_obj(tank, os.path.join(OUT_DIR, "TankUnit.glb"))

    ranged = add_uv_sphere("RangedUnit", 0.45, red)
    export_obj(ranged, os.path.join(OUT_DIR, "RangedUnit.glb"))

    skeleton = add_cube("SkeletonUnit", (0.28, 0.54, 0.28), red)
    export_obj(skeleton, os.path.join(OUT_DIR, "SkeletonUnit.glb"))

    heavy = add_cube("HeavyUnit", (0.55, 0.9, 0.52), red)
    export_obj(heavy, os.path.join(OUT_DIR, "HeavyUnit.glb"))

    tower = add_cube("KingTower", (0.95, 1.3, 0.95), neutral)
    export_obj(tower, os.path.join(OUT_DIR, "KingTower.glb"))

    print(f"Generated low-poly models into: {OUT_DIR}")


generate_units()
