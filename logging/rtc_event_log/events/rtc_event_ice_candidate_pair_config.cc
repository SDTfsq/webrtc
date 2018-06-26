/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "logging/rtc_event_log/events/rtc_event_ice_candidate_pair_config.h"

#include "rtc_base/ptr_util.h"

namespace webrtc {

IceCandidatePairDescription::IceCandidatePairDescription() {
  local_candidate_type = IceCandidateType::kUnknown;
  local_relay_protocol = IceCandidatePairProtocol::kUnknown;
  local_network_type = IceCandidateNetworkType::kUnknown;
  local_address_family = IceCandidatePairAddressFamily::kUnknown;
  remote_candidate_type = IceCandidateType::kUnknown;
  remote_address_family = IceCandidatePairAddressFamily::kUnknown;
  candidate_pair_protocol = IceCandidatePairProtocol::kUnknown;
}

IceCandidatePairDescription::IceCandidatePairDescription(
    const IceCandidatePairDescription& other) {
  local_candidate_type = other.local_candidate_type;
  local_relay_protocol = other.local_relay_protocol;
  local_network_type = other.local_network_type;
  local_address_family = other.local_address_family;
  remote_candidate_type = other.remote_candidate_type;
  remote_address_family = other.remote_address_family;
  candidate_pair_protocol = other.candidate_pair_protocol;
}

IceCandidatePairDescription::~IceCandidatePairDescription() {}

RtcEventIceCandidatePairConfig::RtcEventIceCandidatePairConfig(
    IceCandidatePairConfigType type,
    uint32_t candidate_pair_id,
    const IceCandidatePairDescription& candidate_pair_desc)
    : type_(type),
      candidate_pair_id_(candidate_pair_id),
      candidate_pair_desc_(candidate_pair_desc) {}

RtcEventIceCandidatePairConfig::~RtcEventIceCandidatePairConfig() = default;

RtcEvent::Type RtcEventIceCandidatePairConfig::GetType() const {
  return RtcEvent::Type::IceCandidatePairConfig;
}

// The ICE candidate pair config event is not equivalent to a RtcEventLog config
// event.
bool RtcEventIceCandidatePairConfig::IsConfigEvent() const {
  return false;
}

std::unique_ptr<RtcEvent> RtcEventIceCandidatePairConfig::Copy() const {
  return rtc::MakeUnique<RtcEventIceCandidatePairConfig>(
      type_, candidate_pair_id_, candidate_pair_desc_);
}

}  // namespace webrtc
