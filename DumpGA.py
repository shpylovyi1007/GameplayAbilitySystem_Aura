import unreal

def dump_bp(path, graph_name=None):
    bp = unreal.load_asset(path)
    if not bp:
        print("FAILED LOAD", path)
        return
    print("===", path, "===")
    # Blueprint
    if isinstance(bp, unreal.Blueprint):
        graphs = list(bp.ubergraph_pages) + list(bp.function_graphs)
        for g in graphs:
            if graph_name and g.get_name() != graph_name and getattr(g, "get_display_name", lambda: "")() != graph_name:
                # still print names
                pass
            print("GRAPH:", g.get_name())
            try:
                nodes = g.nodes
            except Exception:
                nodes = []
            for n in nodes:
                cls = n.get_class().get_name()
                title = ""
                try:
                    title = n.get_node_title(unreal.NodeTitleType.FULL_TITLE)
                except Exception:
                    try:
                        title = str(n.get_editor_property("node_comment") or "")
                    except Exception:
                        title = n.get_name()
                print(f"  NODE {n.get_name()} | {cls} | {title}")
                try:
                    pins = n.pins
                except Exception:
                    pins = []
                for p in pins:
                    try:
                        pname = p.get_name()
                        direction = str(p.direction)
                        linked = [f"{lp.get_owning_node().get_name()}.{lp.get_name()}" for lp in p.linked_to]
                        default = ""
                        try:
                            default = p.default_value
                        except Exception:
                            pass
                        if linked or pname.lower() in ("execute","then","onsync","eventreceived","oncompleted","onblendout","oninterrupted","oncancelled","onblendedin","montage_to_play","rate","start_time_seconds","sync_type","event_tag") or default not in ("", None):
                            print(f"    PIN {direction} {pname} default={default} -> {linked}")
                    except Exception as e:
                        print("    pin err", e)

dump_bp("/Game/Blueprints/AbilitySystem/Aura/Abilities/Lightning/GA_Electrocute")
