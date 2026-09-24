import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import ICON_LIGHTBULB
from esphome.types import ConfigType

from . import CONF_TORMATIC_ID, Tormatic, tormatic_ns

TormaticSwitch = tormatic_ns.class_(
    "TormaticSwitch", switch.Switch, cg.Component, cg.Parented.template(Tormatic)
)

CONFIG_SCHEMA = (
    switch.switch_schema(
        TormaticSwitch, default_restore_mode="DISABLED", icon=ICON_LIGHTBULB
    )
    .extend(
        {
            cv.GenerateID(CONF_TORMATIC_ID): cv.use_id(Tormatic),
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config: ConfigType) -> None:
    var = await switch.new_switch(config)
    await cg.register_component(var, config)
    await cg.register_parented(var, config[CONF_TORMATIC_ID])
