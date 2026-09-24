import esphome.codegen as cg
from esphome.components import cover

CODEOWNERS = ["@ti-mo"]

CONF_TORMATIC_ID = "tormatic_id"

tormatic_ns = cg.esphome_ns.namespace("tormatic")
Tormatic = tormatic_ns.class_("Tormatic", cover.Cover, cg.PollingComponent)
